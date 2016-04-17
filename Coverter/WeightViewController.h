//
//  WeightViewController.h
//  Coverter
//
//  Created by iMac on 17.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import "LengthViewController.h"

#pragma mark - ConverterWeightProtocol

@protocol ConverterWeightProtocol <NSObject>

typedef enum {
    ConverterTypeWeightMKG,           //Микрограмм
    ConverterTypeWeightMG,            //Миллиграмм
    ConverterTypeWeightG,             //Грамм
    ConverterTypeWeightKG,            //Килограмм
    ConverterTypeWeightT,             //Тонна
    ConverterTypeWeightOZ,            //Унция
    ConverterTypeWeightLB,            //Фунт
    ConverterTypeWeightSTONE,         //Стоун
    ConverterTypeWeightUSAT,          //Американская тонна
    ConverterTypeWeightEngT           //Английская тонна
} ConverterTypeWeight;

// Возвращает строковое имя типа на русском.
- (NSString*) returnStringWithType:(ConverterTypeWeight) type;

// Принимает число, тип этого числа и тип, в который нужно это число конвертировать. Возвращает конвертированное число.
- (double) convertValue:(double) value fromType:(ConverterTypeWeight) inputType inType:(ConverterTypeWeight) outputType;


@end

@interface WeightViewController : LengthViewController

@end
