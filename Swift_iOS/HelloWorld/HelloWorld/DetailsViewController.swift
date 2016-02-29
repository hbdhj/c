//
//  DetailsViewController.swift
//  HelloWorld
//
//  Created by denghaijun on 16/2/28.
//  Copyright © 2016年 denghaijun. All rights reserved.
//

import UIKit

class DetailsViewController: UIViewController {
    var album: Album?
    @IBOutlet weak var albumCover: UIImageView!
    @IBOutlet weak var titleLabel: UILabel!
    
    required init(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)!
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        titleLabel.text = self.album?.title
        albumCover.image = UIImage(data: NSData(contentsOfURL: NSURL(string: self.album!.largeImageURL)!)!)
    }
}