#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/TestRun.h>
#include <err.h>

#include "writer.h"
#include "message.h"

void startUnitTests();
void haikuPathTest();
void messageQueueTest();

#endif // __UNIT_TEST_H__