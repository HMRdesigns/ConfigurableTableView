//
//  CBConfigurableTableView.h
//  ConfigurableTableView
//
//  Created by Christian Beer on 04.12.09.
//  Copyright 2010 Christian Beer. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "CBTable.h"

@interface CBConfigurableTableViewController : UITableViewController <CBTableDelegate,UITableViewDataSource,UITableViewDelegate> {
	id _data;
	
	CBTable *_model;

    BOOL _kbDidShow;    

    UITableViewRowAnimation _addAnimation;
    UITableViewRowAnimation _removeAnimation;
    UITableViewRowAnimation _reloadAnimation;
    
}

@property (nonatomic, retain) CBTable *model;
@property (nonatomic, retain) id data;

@property (nonatomic, assign) UITableViewRowAnimation addAnimation;
@property (nonatomic, assign) UITableViewRowAnimation removeAnimation;


- (id)initWithTableModel:(CBTable*)model;
- (id)initWithTableModel:(CBTable*)model andData:(NSObject*)object;

- (void) setValue:(id)value forCell:(CBCell*)cell withReload:(BOOL)reload;
- (void) setValue:(id)value forCell:(CBCell*)cell;
- (id) valueForCell:(CBCell*)cell;

- (void) addKeyboardObservers;
- (void) removeKeyboardObservers;

@end
