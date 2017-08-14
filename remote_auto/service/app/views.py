#!/usr/bin/python2.7
#
# Copyright 2017 XiaoMi Inc. All Rights Reserved.


"""One-line documentation for views module.

A detailed description of views.
"""

__author__ = 'xiezhi@xiaomi.com (Xie Zhi)'

from flask import render_template
from flask import jsonify
from flask import request
from app import app
from app import ser


@app.route('/')
@app.route('/index')
def index():
    return render_template("index.html")


cmd_map = {'stop': '0',
           'fow': '1',
           'back': '2',
           'left': '3',
           'right': '4',
           }


@app.route('/control')
def control():
    cmd = request.args.get('cmd')
    ser.write(cmd_map[cmd])

    print "ser write: [%s]" % cmd
    return jsonify({'res': 1})
