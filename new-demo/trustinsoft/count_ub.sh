#!/bin/bash

ME=$(basename $0)
DIR="$(dirname $0)"

res=`cat $*|jq '{status: .alarms.list[].status}' 2>&1|grep -H -E "(NOT OK|unknown)"|wc -l`
if [ "$res" = "" ]; then
    res=`cat $*|jq '{status: .alarms.list.status}'|grep -H -E "(NOT OK|unknown)"|wc -l`
fi
echo $res