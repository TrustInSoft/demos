#!/bin/bash

function count_ub()
{
    cat $* | jq '{status: .alarms.status}'|grep -H '"status": "NOT OK"'|wc -l
}

function clean_report()
{
    rootDir=${2:$(dirname $1)}
    mv $1 $1.bak
    cat $1.bak | sed 's/$rootDir//g' >$1
}