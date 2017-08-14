#!/usr/bin/python2.7
#
# Copyright 2017 XiaoMi Inc. All Rights Reserved.


"""One-line documentation for __init__ module.

A detailed description of __init__.
"""

__author__ = 'xiezhi@xiaomi.com (Xie Zhi)'

import serial
from flask import Flask


app = Flask(__name__, static_folder='assets', static_url_path='/assets')
#ser = serial.Serial("/dev/ttyACM0", 9600)
ser = "test"


from app import views
