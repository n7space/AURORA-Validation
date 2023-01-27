#!/usr/bin/env python3
# -*- coding: utf-8 -*-

''' Edit this module at will to create custom widgets that can send TC or
    receive TM - and do anything you like with the data.
    (c) 2016-2022 European Space Agency / Maxime Perrotin
'''

import sys
import os
import importlib


from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *

from asn1_value_editor import UserWidgetsCommon

__all__ = [
    "TC",
    "TM",
]

# If you want to put all widgets in a single window
# g_mdiArea = None

def user_init_pre(mainWidget):
    ''' This function is called by the auto-generated GUI before the custom
    widgets are instantiated. You may create a MDI area to place the widgets
    in, or do any initialization procedure you need.
    '''
    ...
    # An example that creates a common window and makes sure that when
    # the main GUI is closed, it is also closed
    # global g_mdiArea
    # g_mdiArea = QMdiArea()
    # mainWidget.quitApplication.connect(g_mdiArea.close)
    # print("Initializing the TASTE-RIS GUI")


def user_init_post(instances):
    ''' Called after all instances have been created '''
    ''' This function is called after the initialization of all classes
    that were created during startup, i.e. the ones that returned true to
    the call "run_at_startup"
    All created TC/TM instances are provided ; use them if you need to
    connect signals and slots between them.
    '''
    ...
    # for each in instances:
    #     g_mdiArea.addSubWindow(each)
    #     each.show()
    #     print(f"Initialized {each.name}")
    # g_mdiArea.show()


class TC(UserWidgetsCommon.TC):
    ''' User Widget for telecommand TC  '''
    name = 'TC'  # name on the GUI combo button

    def __init__(self, asn1_typename, parent):
        ''' Initialise the widget '''
        super().__init__(asn1_typename, parent)
        self._asn1_typename = asn1_typename

        # parent is the ASN.1 value editor
        # You can use it to send the telecomamnd to the application.
        # use self.parent.asn1Instance.Set(...)  # ASN.1 API
        # to set the parameter value (if any)
        # then self.parent.updateVariable() to update the editor window
        # then optionally self.parent.sendTC() to actually send the message
        # If you need to get the value set in the editor, use:
        # self.parent.getVariable(dest=self.parent.asn1Instance)

        self.parent = parent
        self.setWindowTitle("TC TC")
        self.show()

    @staticmethod
    def run_at_startup():
        ''' Return true if you want this widget to be created automatically
        when the GUI starts. This is useful to initialize a complete GUI
        replacement in combination with the user_init function that can
        create a common GUI area for all widgets '''
        return False

    @staticmethod
    def applicable():
        ''' Return True to activate this widget '''
        return False

    @staticmethod
    def editorIsApplicable(editor):
        ''' Do not change this function '''
        return editor.messageName == "TC"

class TM(UserWidgetsCommon.TM):
    ''' User widget for telemetry TM '''
    name = 'TM'  # name for the combo button in the GUI

    def __init__(self, parent=None):
        ''' Initialise the widget '''
        super().__init__(parent)
        self.parent = parent
        self.setWindowTitle("TC TM")
        self.show()

    @Slot()
    def new_tm(self):
        ''' Slot called when a TM has been received in the editor. The GUI
        sends this signal just before calling the update() function with
        the ASN.1 value.
        '''
        # Most of the time you can ignore this and just process data in the
        # update() function.
        print("[TM] Received Telemetry")

    def update(self, value):
        ''' Receive ASN.1 value. This function is called by the main GUI
        (synchronous call) when it gets a TM from its message queue. '''
        # use e.g. value.Get().. (see ASN.1 Python API)
        pass

    @staticmethod
    def run_at_startup():
        ''' Return true if you want this widget to be created automatically
        when the GUI starts. This is useful to initialize a complete GUI
        replacement in combination with the user_init function that can
        create a common GUI area for all widgets '''
        return False

    @staticmethod
    def applicable():
        ''' Return True to enable this widget in general '''
        return False

    @staticmethod
    def editorIsApplicable(editor):
        ''' Do not change this function '''
        return editor.messageName == "TM"


if __name__ == '__main__':
    print('This module can only be imported from the main TASTE guis')
    sys.exit(-1)