#pragma once

#include <PlayFabServerSdk/PlayFabError.h>

namespace PlayFabServerSdk
{
    class PlayFabSettings
    {
    public:
        static PlayFabSettings *playFabSettings; // Global settings for all Apis

        const AZStd::string playFabVersionString;
        const AZStd::string buildIdentifier;

        bool useDevelopmentEnvironment;
        AZStd::string developmentEnvironmentURL;
        AZStd::string productionEnvironmentURL;
        AZStd::string titleId; // You must set this value for PlayFab to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        ErrorCallback globalErrorHandler;
        AZStd::string developerSecretKey; // You must set this value for PlayFab to work properly (Found in the Game Manager for your title, at the PlayFab Website)

        PlayFabSettings();

        AZStd::string getURL(const AZStd::string& callPath)
        {
            if (serverURL.length() == 0)
                serverURL = "https://" + titleId + (useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL);
            return serverURL + callPath;
        }

    private:
        AZStd::string serverURL; // A cache of the constructed url string
    };
}
