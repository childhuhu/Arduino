#!/usr/bin/env python
#
# Copyright 2017 XiaoMi Inc. All Rights Reserved.


"""One-line documentation for run module.

A detailed description of run.
"""

__author__ = 'xiezhi@xiaomi.com (Xie Zhi)'

import sys
from app import app

def main(argv):
    app.run(host='0.0.0.0', port = 8000)


if __name__ == '__main__':
  main(sys.argv)
