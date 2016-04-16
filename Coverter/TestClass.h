//
//  TestClass.h
//  Coverter
//
//  Created by iMac on 16.04.16.
//  Copyright © 2016 MilNik. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LengthViewController.h"

@protocol ConverterLengthProtocol;

@interface TestClass : NSObject <ConverterLengthProtocol>

// Возвращает строковое имя типа на русском.
- (NSString*) returnStringWithType:(ConverterTypeLength) type;

// Принимает число, тип этого числа и тип, в который нужно это число конвертировать. Возвращает конвертированное число.
- (double) convertValue:(double) value fromType:(ConverterTypeLength) type_1 inType:(ConverterTypeLength) type_2;



@end
