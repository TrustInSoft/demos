#!/bin/bash

ME=$(basename $0)
DIR="$(dirname $0)"

cat $*|jq '{status: .alarms.status}'|grep -H '"status": "NOT OK"'|wc -l