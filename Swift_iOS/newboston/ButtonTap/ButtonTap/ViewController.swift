//
//  ViewController.swift
//  ButtonTap
//
//  Created by denghaijun on 16/2/21.
//  Copyright © 2016年 denghaijun. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var buckysLabel: UILabel!
    
    @IBAction func buttonPressed(sender: UIButton) {
        let title = sender.titleForState(.Normal)!
        
        buckysLabel.text = "You have clicked the \(title) button!"
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

