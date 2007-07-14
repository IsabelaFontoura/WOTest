//
//  WOTestLowLevelException.h
//  WOTest
//
//  Created by Wincent Colaiuta on 22 October 2006.
//
//  Copyright 2006-2007 Wincent Colaiuta.
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  $Id: WOTestLowLevelException.h 208 2007-07-07 19:02:28Z wincent $

#import <Cocoa/Cocoa.h>

@interface WOTestLowLevelException : NSException {

}

+ (WOTestLowLevelException *)exceptionWithType:(ExceptionKind)kind;

//! Utility method for converting a numeric exception kind into a human-readable NSString.
+ (NSString *)nameForType:(ExceptionKind)kind;

@end

extern NSString *WOTestLowLevelExceptionName;
extern NSString *WOTestLowLevelExceptionKind;