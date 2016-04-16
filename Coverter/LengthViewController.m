//
//  LengthViewController.m
//  Coverter
//
//  Created by iMac on 16.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import "LengthViewController.h"

// тип числа на экране
typedef enum {
    CalculatorTypeNumberInteger,
    CalculatorTypeNumberFraction
} CalculatorTypeNumber;

@interface LengthViewController()

@property (strong, nonatomic) id <ConverterLengthProtocol> delegate;
@property (strong, nonatomic) NSMutableString* indicatorString; // строка, которая выводиться на valueLabel
@property (assign, nonatomic) double indicatorNumber; // число, которое введено на экране
@property (assign, nonatomic) CalculatorTypeNumber typeNumber; // флаг, для определения дробного числа (введенного с клавиатуры). Нужен для предотвраащения повторного добавления точки!

@end

@implementation LengthViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    for (UIButton* button in self.numberButton) {
        button.layer.cornerRadius = 10.f;
    }
    
    self.indicatorString = [[NSMutableString alloc] initWithString:@"0"]; // стандартный ноль на экране калькулятора
    self.indicatorNumber = 0.f;
    self.typeNumber = 0;
    
}


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

#pragma mark - Action buttons

- (IBAction)actionNumberButton:(UIButton *)sender {
    
    if ([self.indicatorString isEqualToString:@"0"]) {
        [self.indicatorString setString:@""];
    }
    
    if (self.indicatorString.length < 11) {
        
        NSString* number = [NSString string];
        
        switch (sender.tag) {
            case 0:
                number = @"0";
                break;
            case 1:
                number = @"1";
                break;
            case 2:
                number = @"2";
                break;
            case 3:
                number = @"3";
                break;
            case 4:
                number = @"4";
                break;
            case 5:
                number = @"5";
                break;
            case 6:
                number = @"6";
                break;
            case 7:
                number = @"7";
                break;
            case 8:
                number = @"8";
                break;
            case 9:
                number = @"9";
                break;
                
            default:
                break;
        }
        
        [self.indicatorString appendString:number];
    }
    
    [self saveNumber];
    
    [self outputOnDisplay];
    
}

- (IBAction)actionAddFractionButton:(UIButton *)sender {
    
    if (!self.typeNumber) {
        
        if (self.indicatorString.length < 10) {
            
            if (sender.tag == 500) {
                
                [self.indicatorString appendString:@"."];
            }
        }
        
        self.typeNumber = CalculatorTypeNumberFraction;
        
        [self outputOnDisplay];
    }
    
}

- (IBAction)actionAllClearButton:(UIButton *)sender {
    
    // ALL CLEAR
    if (sender.tag == 100) {
        self.indicatorNumber = 0.f;
        [self.indicatorString setString:@"0"];
        self.typeNumber = 0;
    }
    
    [self outputOnDisplay];
    
}

#pragma mark - Additional methods

// вывод на экран
- (void) outputOnDisplay {
    self.valueLabel.text = self.indicatorString;
}

// сохранение текущего числа на экране в "память" (в переменную self.indicatorNumber)
- (void) saveNumber {
    
    self.indicatorNumber = [self.indicatorString doubleValue];
}
@end
