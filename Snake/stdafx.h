#pragma once

#include <queue>
#include <vector>
#include <memory>
#include <thread>
#include <atomic>
#include <Windows.h>
#include <mutex>
#include <conio.h>
#include <iostream>

#define _TRACE(msg) 

#define _S_CHECK(exp, result) { if (exp == result) { return result; } }

#include "Interfaces.h"
#include "Point.h"
#include "Field.h"
#include "Snake.h"
