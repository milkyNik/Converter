//
//  WeightViewController.m
//  Coverter
//
//  Created by iMac on 17.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import "WeightViewController.h"
#import "WeightConverter.h"

@interface WeightViewController()

@property (strong, nonatomic) id <ConverterWeightProtocol> weightDelegate;
@property (assign, nonatomic) ConverterTypeWeight inputTypeWeight;
@property (assign, nonatomic) ConverterTypeWeight outputTypeWeight;

@end

@implementation WeightViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    WeightConverter* testConverter = [[WeightConverter alloc] init];
    self.weightDelegate = testConverter;
    
}


#pragma mark - UIPickerViewDelegate

// метод заполнения полей в PickerView
- (nullable NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    
    if (component == 1) {
        return @"B";
    }
    
    return [self.weightDelegate returnStringWithType:row];
    
}

// метод реагирующий на выбор в PickerView
- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    
    if (component == 0) {
        self.inputTypeWeight = row;
    } else if (component == 2) {
        self.outputTypeWeight = row;
    }
    
    [self convert];
    
}

#pragma mark - UIPickerViewDataSource

// returns the # of rows in each component..
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    
    if (component == 1) {
        return 1;
    }
    
    return 10;
    
}

#pragma mark - Additional methods

// конвертирование и вывод на экран
- (void) convert {
    
    NSLog(@"%f",self.indicatorNumber);
    
    double convertValue = [self.weightDelegate convertValue:self.indicatorNumber fromType:self.inputTypeWeight inType:self.outputTypeWeight];
    
    self.convertValueLabel.text = [NSString stringWithFormat:@"%.11g", convertValue];
    
}

@end
