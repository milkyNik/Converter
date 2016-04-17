//
//  WeightConverter.h
//  Coverter
//
//  Created by iMac on 17.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WeightViewController.h"

@protocol ConverterWeightProtocol;

@interface WeightConverter : NSObject <ConverterWeightProtocol>

// Возвращает строковое имя типа на русском.
- (NSString*) returnStringWithType:(ConverterTypeWeight) type;

// Принимает число, тип этого числа и тип, в который нужно это число конвертировать. Возвращает конвертированное число.
- (double) convertValue:(double) value fromType:(ConverterTypeWeight) inputType inType:(ConverterTypeWeight) outputType;

@end
