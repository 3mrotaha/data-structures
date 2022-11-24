#ifndef _APP_PRIVATE_
#define _APP_PRIVATE_

static AppError_t	AppInit(void);

static AppError_t	LaunchPlane(Time_t);

static AppError_t	CheckLanding(Time_t);

static AppError_t	CheckTakeoff(Time_t);

static AppError_t PushToAir(Time_t);

static AppError_t PopFromAir(Time_t);

static AppError_t PopFromRunWay(Time_t);

static AppError_t DestroyApp(void);

static AppError_t AirPortStatus(Time_t);

#endif

