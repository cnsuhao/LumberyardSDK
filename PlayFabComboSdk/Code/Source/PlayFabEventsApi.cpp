#include "StdAfx.h"
#include "PlayFabEventsApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabComboSdk;

// PlayFabEvents Api
PlayFabEventsApi::PlayFabEventsApi() {}

void PlayFabEventsApi::WriteEvents(
    EventsModels::WriteEventsRequest& request,
    ProcessApiCallback<EventsModels::WriteEventsResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Event/WriteEvents"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnWriteEventsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabEventsApi::OnWriteEventsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        EventsModels::WriteEventsResponse* outResult = new EventsModels::WriteEventsResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<EventsModels::WriteEventsResponse> successCallback = reinterpret_cast<ProcessApiCallback<EventsModels::WriteEventsResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

