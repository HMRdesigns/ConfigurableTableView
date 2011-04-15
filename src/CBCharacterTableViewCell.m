//
//  CBCharacterTableViewCell.m
//  ConfigurableTableView
//
//  Created by Christian Beer on 07.07.10.
//  Copyright 2010 Christian Beer. All rights reserved.
//

#import "CBCharacterTableViewCell.h"

#import "CBCTVGlobal.h"

@interface CBCharacterTableViewCell (Private) <UITextFieldDelegate>

@end


@implementation CBCharacterTableViewCell

@synthesize textField = _textField;

- (id)initWithReuseIdentifier:(NSString *)reuseIdentifier {
	if (self = [super initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIdentifier]) {
		_textField = [[UITextField alloc] initWithFrame:CGRectMake(0.0, 0.0, 50.0, 30.0)];
		_textField.font = [UIFont systemFontOfSize:18];
		_textField.textAlignment = UITextAlignmentRight;
        _textField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
        _textField.delegate = self;
        _textField.textColor = [UIColor tableViewCellValueTextColor];
		[self.contentView addSubview:_textField];
		[_textField release];
		
		self.selectionStyle = UITableViewCellSelectionStyleNone;
	}
	return self;
}

- (void) dealloc {
    _textField.delegate = nil;
    
    [super dealloc];
}


#define kCellLeftOffset     8.0
#define kCellTopOffset		10.0

- (void)layoutSubviews {
	[super layoutSubviews];
    CGRect r = [self.contentView bounds];
    
    r.origin.x += kCellLeftOffset;
    r.size.width -= kCellLeftOffset * 2;

    _textField.frame = r;
	
    r.size.width -= 50;
    self.textLabel.frame = r;
}

- (void)stopEditing {
    [_textField resignFirstResponder];
//    [self textFieldDidEndEditing:_textField];
}

#pragma mark <UITextFieldDelegate> Methods

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
	if ([_textField.text length] == 1) {
		[self stopEditing];
		return YES;
	} else {
		return NO;
	}
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    if (_textField.text.length >= 1 && range.length == 0) {
        string = [string substringToIndex:1];
        
        _textField.text = string;
        
        if (self.object && self.keyPath) {
            [self.object setValue:string 
                       forKeyPath:self.keyPath];
        }

		return NO; // return NO to not change text
	}
    return YES;
}

@end
