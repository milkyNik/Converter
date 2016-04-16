//
//  LengthViewController.m
//  Coverter
//
//  Created by iMac on 16.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import "LengthViewController.h"

@implementation LengthViewController




#pragma mark - UIPickerViewDataSource

// returns the number of 'columns' to display.
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    
    return 3;
}

// returns the # of rows in each component..
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    
    if (component == 1) {
        return 1;
    }
    
    return 9;
    
}

// метод заполнения полей в PickerView
- (nullable NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    
    if (component == 1) {
        return @"B";
    }
    
    return [self.delegate returnStringWithType:row];
    
}

#pragma mark - UIPickerViewDelegate

// метод реагирующий на выбор в PickerView
- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    
    
    
}

@end
