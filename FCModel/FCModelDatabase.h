//
//  FCModelDatabase.h
//
//  Created by Marco Arment on 3/12/14.
//  Copyright (c) 2014 Marco Arment. See included LICENSE file.
//

#import <Foundation/Foundation.h>

@class FMDatabase;

@interface FCModelDatabase : NSObject

- (instancetype)initWithDatabasePath:(NSString *)filename;
- (void)startMonitoringForExternalChanges;
- (void)close;
- (void)inDatabase:(void (^)(FMDatabase *db))block;

@property (nonatomic, readonly) FMDatabase *database;
@property (nonatomic, readonly) NSMutableDictionary *enqueuedChangedFieldsByClass;
@property (nonatomic) BOOL isQueuingNotifications;
@property (nonatomic) BOOL isInInternalWrite;

@end
