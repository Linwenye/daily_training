import pymongo
from pprint import pprint

client = pymongo.MongoClient()
db = client['moodle']
collection = db['course']

cursor = collection.find({'key': '101'})
exist = cursor[0]
pprint(exist)

dict1 = {'children': [{'children': [{'key': '1853',
                                     'name': 'Assignment 1: Quality Attributes &amp; '
                                             'Tactics'},
                                    {'key': '1908',
                                     'name': 'Assignment 2: Blockchain Architecture '
                                             'Analysis'},
                                    {'key': '1901', 'name': 'Project Proposal'}],
                       'key': '533',
                       'name': '作业'},
                      {'children': [{'key': '1910', 'name': 'Lecture 01: Blockchain'},
                                    {'key': '1857', 'name': 'Lecture 03: Introduction'},
                                    {'key': '1858',
                                     'name': 'Lecture 04-06: Quality Attributes &amp; '
                                             'Tactics'},
                                    {'key': '1907',
                                     'name': 'Lecture 06-08: Architectural Patterns'},
                                    {'key': '1908',
                                     'name': 'Lecture 09-10: s'}],
                       'key': '532',
                       'name': '课件'},
                      {'children': [{'key': '1902', 'name': '作业补交说明'}],
                       'key': '531',
                       'name': '通知'},
                      {'children': [{'key': '1766', 'name': '新闻讨论区'}],
                       'key': '518',
                       'name': '常规'}],
         'key': '101',
         'name': '软件系统设计与体系结构1班(2017 Winter)'}

for sub_item1, sub_item2 in zip(dict1['children'], exist['children']):
    if not sub_item1 == sub_item2:
        print(type(sub_item1['children']))
        list1 = sub_item1['children']
        list2 = sub_item2['children']

        for tt in list1:
            if tt not in list2:
                print(tt, sub_item1['name'])
