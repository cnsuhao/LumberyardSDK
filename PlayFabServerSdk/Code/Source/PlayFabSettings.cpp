#include "StdAfx.h"
#include "PlayFabSettings.h"

using namespace PlayFabServerSdk;

PlayFabSettings * PlayFabSettings::playFabSettings = nullptr; // Global settings for all Apis

PlayFabSettings::PlayFabSettings() :
    playFabVersionString("LumberyardSDK-0.0.171102"),
    buildIdentifier("jbuild_lumberyardsdk_0"),
    useDevelopmentEnvironment(false),
    developmentEnvironmentURL(".playfabsandbox.com"),
    productionEnvironmentURL(".playfabapi.com"),
    titleId(), // You must set this value for PlayFab to work properly (Found in the Game Manager for your title, at the PlayFab Website)
    globalErrorHandler(nullptr),
    developerSecretKey(), // You must set this value for PlayFab to work properly (Found in the Game Manager for your title, at the PlayFab Website)
    serverURL()
{};
