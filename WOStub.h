//
//  WOStub.h
//  WOTest
//
//  Created by Wincent Colaiuta on 14/06/05.
//
//  Copyright 2005-2007 Wincent Colaiuta.
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
//  $Id: WOStub.h 208 2007-07-07 19:02:28Z wincent $

#import <Foundation/Foundation.h>

/*! The WOStub class provides a temporary "trampoline" object that can be used to record invocations (selectors and arguments) and desired return values. It is a "stub" because it is a temporary object that operates behind the scenes and is effectively indistinguishable from the object for which it temporarily stands in. It is a "trampoline" because it serves to bounce back the invocations and desired return values to the object for which it temporarily stands in. */
@interface WOStub : NSProxy {
    
    id              delegate;
    
    NSInvocation    *invocation;
    
    NSValue         *returnValue;
        
    id              exception;
    
    /*! YES if the stub should accept any arguments. The default behaviour (NO) indicates that the stub should only accept the arguments that were passed when it was first created and any discrepancies will result in an exception. */
    BOOL            acceptsAnyArguments;
}

/*! Basic initizialer available for use by subclasses. Do not call directly. */
- (id)init;

/*! Used to indicate that the stub should accept any arguments when determining whether or not an invocation matches. The default is that the stub requires all arguments to match or it will raise an exception. */
- (id)anyArguments;

#pragma mark -
#pragma mark Recording

/*! Used to specify the return value that should be sent in response to messages. */
- (id)returning:(NSValue *)aValue;

/*! Used to specify the exception that should be raised in response to messages. \p anException should respond to the retain, release, autorelease, isEqual and hash selectors. */
- (id)raising:(id)anException;

#pragma mark -
#pragma mark Testing equality

/*! Convenience method for comparing a stub against an invocation. If no invocation has yet been recorded when this method is called raises an exception. Raises if \p anInvocation is nil. */
- (BOOL)matchesInvocation:(NSInvocation *)anInvocation;

#pragma mark -
#pragma mark Accessors

- (BOOL)acceptsAnyArguments;
- (void)setAcceptsAnyArguments:(BOOL)flag;

/*! Returns the recorded invocation object stored by this instance. Raises an exception if no invocation has yet been recorded. */
- (NSInvocation *)recordedInvocation;

/*! Direct access to the invocation instance variable. Should not be used. Use recordedInvocation instead. */
- (NSInvocation *)invocation;
- (void)setInvocation:(NSInvocation *)anInvocation;

- (NSValue *)returnValue;
- (void)setReturnValue:(NSValue *)aReturnValue;

- (id)exception;
- (void)setException:(id)anException;

@end