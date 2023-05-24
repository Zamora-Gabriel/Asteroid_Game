#pragma once

const int kViewportWidth = 800;
const int kViewportHeight = 600;

const float fRateRequired = (1 / 60.0f);			// 60 FPS
const float fRateMinimum = (1 / 10.0f);			// 10 FPS
const float fWaitThreshold = (5 / 1000.0f);		// 5ms
const float fSleepSlack = (2 / 1000.0f);			// 2ms
const float fSliceThreshold = (1 / 1000.0f);		// 1ms