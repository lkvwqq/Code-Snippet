# Python 3.5.2

import platform
# 获取 Python 的版本号
print(platform.python_version())

import time
# 获取当前时间
print(time.strftime("%Y-%m-%d %H:%M:%S",time.localtime(time.time())))

import os
# 获取当前工作目录
print(os.getcwd())

# 改变当前工作目录
os.chdir('E:/MyCode')
print(os.getcwd())

# 获取当前用户主目录
print(os.path.expanduser('~'))

# 判断目录是否存在并创建
if not os.path.exists("E:/MyCode"):
    os.mkdir("E:/MyCode")

# 列出目录下文件
import glob
print(glob.glob('E:/MyCode/Python/*.py'))
print(glob.glob('E:/MyCode/Python/*test*.py'))

# 拼接文件名
print(os.path.join('E:/MyCode/Python/', 'FileRelated.py'))
print(os.path.join('E:/MyCode/Python', 'FileRelated.py'))
print(os.path.join(os.path.expanduser('~'), 'MyCode', 'Python', 'FileRelated.py'))

# 拆分文件名
(dirname, filename) = os.path.split('E:\\MyCode\\Python\\FileRelated.py')
print("dirname:{}, filename:{}".format(dirname, filename))
(shortname, extension) = os.path.splitext(filename)
print("shortname:{}, extension:{}".format(shortname, extension))

# 获取文件绝对路径
# curWorkDir + fileName
print(os.path.realpath('feed.xml'))

# 获取文件属性
metadata = os.stat('E:/MyCode/Python/FileRelated.py')
# 文件大小
print(metadata.st_size)
# 文件创建时间
print(time.localtime(metadata.st_mtime))




