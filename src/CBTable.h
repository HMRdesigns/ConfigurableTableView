//
//  CBTableView.h
//  ConfigurableTableView
//
//  Created by Christian Beer on 04.12.09.
//  Copyright 2010 Christian Beer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class CBTable;
@class CBSection;
@class CBCell;

@protocol CBSectionDelegate;

@protocol CBTableDelegate <NSObject>

- (void) table:(CBTable*)table sectionAdded:(CBSection*)section;
- (void) table:(CBTable*)table sectionRemovedAtIndex:(NSUInteger)index;

- (void) table:(CBTable*)table section:(CBSection*)section cellAdded:(CBCell*)cell;
- (void) table:(CBTable*)table section:(CBSection*)section cellsAdded:(NSArray*)cells;
- (void) table:(CBTable*)table section:(CBSection*)section cellRemovedAtIndexPath:(NSIndexPath*)indexPath;
- (void) table:(CBTable*)table section:(CBSection*)section cellsRemovedAtIndexPaths:(NSArray*)indexPaths;

@end


@interface CBTable : NSObject {
	NSMutableArray *_sections;
	
	id<CBTableDelegate> __weak _delegate;
}

@property (nonatomic, weak) id<CBTableDelegate> delegate;

@property (weak, readonly) NSArray *sections;


- (id) init;
- (id) initWithSections:(NSArray*)sections;

+ (CBTable*) table;
+ (CBTable*) tableWithSectionArray:(NSArray*)sections;
+ (CBTable*) tableWithSections:(CBSection*)section, ...NS_REQUIRES_NIL_TERMINATION;

- (NSUInteger) sectionCount;
- (id) sectionAtIndex:(NSUInteger)index;
- (NSUInteger) indexOfSection:(CBSection*)section;
- (NSUInteger) indexOfSectionWithTag:(NSString*)tag;
- (id) addSection:(CBSection*)section;
- (id) insertSection:(CBSection*)section atIndex:(NSUInteger)index;
- (void) removeSection:(CBSection*)section;
- (void) addSections:(CBSection*)section, ...NS_REQUIRES_NIL_TERMINATION;

- (id) sectionWithTag:(NSString*)tag;
- (id) cellWithTag:(NSString*)tag;
- (id) cellWithValueKeyPath:(NSString*)valuePath;

- (NSIndexPath*) indexPathOfCell:(CBCell*)cell;
- (NSIndexPath*) indexPathOfCellWithTag:(NSString*)cellTag;
- (id) cellForRowAtIndexPath:(NSIndexPath *)indexPath;

@end


@interface CBTable (Private)
	
- (void) addSectionsVargs:(va_list)args;

@end