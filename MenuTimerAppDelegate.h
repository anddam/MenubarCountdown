//
//  MenuTimerAppDelegate.h
//  MenuTimer
//
//  Created by Kristopher Johnson on 3/19/09.
//  Copyright 2009 Capable Hands Technologies, Inc.. All rights reserved.
//
//  This file is part of Menubar Countdown.
//
//  Menubar Countdown is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Menubar Countdown is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Menubar Countdown.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Cocoa/Cocoa.h>

@class Stopwatch;
@class StartTimerDialogController;
@class TimerExpiredAlertController;
@class GrowlHandler;

typedef enum {
    kTimerStateStarting,
    kTimerStateRunning,
    kTimerStatePaused,
    kTimerStateStopped,
    kNumTimerStates
} kTimerStates;

/// \brief Application delegate
@interface MenuTimerAppDelegate : NSObject <NSMenuDelegate> {
    int timerSettingSeconds;   ///< Timer setting
    int secondsRemaining;      ///< Number of seconds remaining

    kTimerStates _timerState;
    NSStatusItem *statusItem;  ///< Reference to NSStatusItem

    IBOutlet NSMenu *menu;                                             ///< Outlet for main menu
    IBOutlet Stopwatch *stopwatch;                                     ///< Outlet for Stopwatch
    IBOutlet StartTimerDialogController *startTimerDialogController;   ///< Outlet for StartTimerDialogController
    IBOutlet TimerExpiredAlertController *timerExpiredAlertController; ///< Outlet for TimerExpiredAlertController
    IBOutlet GrowlHandler *growl;                                      ///< Outlet for GrowlHandler
}

@property (nonatomic, assign) kTimerStates timerState;
@property (nonatomic, readonly) BOOL timerIsStarted;

/// \brief Indicates whether the timer is running
///
/// This property is bound to the Stop menu item's Enabled property
//@property (nonatomic) BOOL timerIsRunning;

/// \brief Handle the "About..." menu item
- (IBAction)showAboutPanel:(id)sender;

/// \brief Start the timer
///
/// Displays the StartTimerDialogController's window
- (IBAction)startStopTimer:(id)sender;

/// \brief Stop the timer
- (IBAction)pauseResumeTimer:(id)sender;

- (IBAction)resetTimer:(id)sender;

/// \brief Invoked when the Start button on the StartTimerDialogController's window is clicked
- (IBAction)startTimerDialogStartButtonWasClicked:(id)sender;
- (IBAction)startTimerDialogCancelButtonWasClicked:(id)sender;

/// \brief Invoked when OK button is clicked in timer-expired alert window
- (IBAction)dismissTimerExpiredAlert:(id)sender;

@end
