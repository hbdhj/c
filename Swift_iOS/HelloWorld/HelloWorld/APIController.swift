//
//  APIController.swift
//  HelloWorld
//
//  Created by denghaijun on 16/2/28.
//  Copyright © 2016年 denghaijun. All rights reserved.
//

import Foundation

protocol APIControllerProtocol {
    func didReceiveAPIResults(results: NSArray)
}

class APIController {
    var delegate: APIControllerProtocol?

    func searchItunesFor(searchTerm: String) {

        // The iTunes API wants multiple terms separated by + symbols, so replace spaces with + signs
        let itunesSearchTerm = searchTerm.stringByReplacingOccurrencesOfString(" ", withString: "+", options: NSStringCompareOptions.CaseInsensitiveSearch, range: nil)

        // Now escape anything else that isn't URL-friendly stringByAddingPercentEncodingWithAllowedCharacters
        if let escapedSearchTerm = itunesSearchTerm.stringByAddingPercentEscapesUsingEncoding(NSUTF8StringEncoding) {
            //if let escapedSearchTerm = itunesSearchTerm.stringByAddingPercentEncodingWithAllowedCharacters() {
            //{
            let urlPath = "http://itunes.apple.com/search?term=\(escapedSearchTerm)&media=software"
            //let urlPath = "http://localhost/json.php"
            let url = NSURL(string: urlPath)
            let session = NSURLSession.sharedSession()

            let task = session.dataTaskWithURL(url!, completionHandler: {data, response, error -> Void in
                print("Task completed")

                do {
                    if let jsonResult = try NSJSONSerialization.JSONObjectWithData(data!, options: NSJSONReadingOptions.MutableContainers) as? NSDictionary {
                        if let results: NSArray = jsonResult["results"] as? NSArray {
                        //if let results: NSArray = jsonResult["actions"] as? NSArray {
                            dispatch_async(dispatch_get_main_queue(), {
                                //self.tableData = results
                                //self.appsTableView!.reloadData()
                                self.delegate?.didReceiveAPIResults(results)
                            })
                        }
                    }
                }
                catch
                {
                    print("Something went wrong!")
                }
            })

            // The task is just an object with all these properties set
            // In order to actually make the web request, we need to "resume"
            task.resume()
        }
    }
}
