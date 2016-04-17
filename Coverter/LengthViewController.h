//
//  LengthViewController.h
//  Coverter
//
//  Created by iMac on 16.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import <UIKit/UIKit.h>


#pragma mark - ConverterLengthProtocol

@protocol ConverterLengthProtocol <NSObject>

typedef enum {
    ConverterTypeLengthMM,            //мм
    ConverterTypeLengthCM,            //см
    ConverterTypeLengthDM,            //дм
    ConverterTypeLengthM,             //м
    ConverterTypeLengthKM,            //км
    ConverterTypeLengthInch,          //дюйм
    ConverterTypeLengthFoot,          //фут
    ConverterTypeLengthYard,          //ярд
    ConverterTypeLengthInchesMile     //миля
} ConverterTypeLength;

// Возвращает строковое имя типа на русском.
- (NSString*) returnStringWithType:(ConverterTypeLength) type;

// Принимает число, тип этого числа и тип, в который нужно это число конвертировать. Возвращает конвертированное число.
- (double) convertValue:(double) value fromType:(ConverterTypeLength) type_1 inType:(ConverterTypeLength) type_2;

@end

// тип числа на экране
typedef enum {
    CalculatorTypeNumberInteger,
    CalculatorTypeNumberFraction
} CalculatorTypeNumber;


@interface LengthViewController : UIViewController <UIPickerViewDelegate, UIPickerViewDataSource>

@property (weak, nonatomic) IBOutlet UILabel *valueLabel;
@property (weak, nonatomic) IBOutlet UILabel *convertValueLabel;

@property (strong, nonatomic) IBOutletCollection(UIButton) NSArray *numberButton;

- (IBAction)actionNumberButton:(UIButton *)sender;
- (IBAction)actionAddFractionButton:(UIButton *)sender;
- (IBAction)actionAllClearButton:(UIButton *)sender;


@property (strong, nonatomic) id <ConverterLengthProtocol> lengthDelegate;
@property (strong, nonatomic) NSMutableString* indicatorString; // строка, которая выводиться на valueLabel
@property (assign, nonatomic) double indicatorNumber; // число, которое введено на экране
@property (assign, nonatomic) CalculatorTypeNumber typeNumber; // флаг, для определения дробного числа (введенного с клавиатуры). Нужен для предотвраащения повторного добавления точки!

@property (assign, nonatomic) ConverterTypeLength inputTypeLength;
@property (assign, nonatomic) ConverterTypeLength outputTypeLength;




@end
