#include "StdAfx.h"
#include "PlayFabClientApi.h"
#include "PlayFabSettings.h"

using namespace PlayFabClientSdk;

// Client-Specific
AZStd::string PlayFabClientApi::mUserSessionTicket;

bool PlayFabClientApi::IsClientLoggedIn()
{
    return mUserSessionTicket.length() != 0;
}

// #THIRD_KIND_PLAYFAB_SHUTDOWN_FIXES: - Added a logout function so that the statics can be destroyed before the system allocator.
void PlayFabClientApi::ForgetClientCredentials()
{
    // #THIRD_KIND_PLAYFAB_CRASH_WHEN_PC_IS_OFFLINE: szaluga (2017/08/05)
    // We're taking advantage of the SSO optimization implemented by AZStd::string (and virtually all popular compilers) -
    // small strings are using an internal buffer instead of the allocator.
    // Note: This was not possible with Aws::String, as it deliberately disabled SSO to fix some Android/gcc issuses,
    // but now that PlayFab uses AZStd::string, it should be safe to rely on this behaviour.
    mUserSessionTicket.set_capacity(0);
}

void PlayFabClientApi::MultiStepClientLogin(bool needsAttribution)
{
    if (needsAttribution && !PlayFabSettings::playFabSettings->disableAdvertising && PlayFabSettings::playFabSettings->advertisingIdType.length() > 0 && PlayFabSettings::playFabSettings->advertisingIdValue.length() > 0)
    {
        ClientModels::AttributeInstallRequest request;
        if (PlayFabSettings::playFabSettings->advertisingIdType == PlayFabSettings::playFabSettings->AD_TYPE_IDFA)
            request.Idfa = PlayFabSettings::playFabSettings->advertisingIdValue;
        else if (PlayFabSettings::playFabSettings->advertisingIdType == PlayFabSettings::playFabSettings->AD_TYPE_ANDROID_ID)
            request.Adid = PlayFabSettings::playFabSettings->advertisingIdValue;
        else
            return;
        AttributeInstall(request, nullptr, nullptr);
    }
}

// PlayFabClient Api
PlayFabClientApi::PlayFabClientApi() {}

void PlayFabClientApi::AcceptTrade(
    ClientModels::AcceptTradeRequest& request,
    ProcessApiCallback<ClientModels::AcceptTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AcceptTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAcceptTradeResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAcceptTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AcceptTradeResponse* outResult = new ClientModels::AcceptTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AcceptTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AcceptTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddFriend(
    ClientModels::AddFriendRequest& request,
    ProcessApiCallback<ClientModels::AddFriendResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddFriendResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddFriendResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AddFriendResult* outResult = new ClientModels::AddFriendResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AddFriendResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AddFriendResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddGenericID(
    ClientModels::AddGenericIDRequest& request,
    ProcessApiCallback<ClientModels::AddGenericIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddGenericID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddGenericIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddGenericIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AddGenericIDResult* outResult = new ClientModels::AddGenericIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AddGenericIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AddGenericIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddSharedGroupMembers(
    ClientModels::AddSharedGroupMembersRequest& request,
    ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddSharedGroupMembersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddSharedGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AddSharedGroupMembersResult* outResult = new ClientModels::AddSharedGroupMembersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AddSharedGroupMembersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddUsernamePassword(
    ClientModels::AddUsernamePasswordRequest& request,
    ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddUsernamePassword"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddUsernamePasswordResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddUsernamePasswordResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AddUsernamePasswordResult* outResult = new ClientModels::AddUsernamePasswordResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AddUsernamePasswordResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AddUsernamePasswordResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AddUserVirtualCurrency(
    ClientModels::AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ModifyUserVirtualCurrencyResult* outResult = new ClientModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AndroidDevicePushNotificationRegistration(
    ClientModels::AndroidDevicePushNotificationRegistrationRequest& request,
    ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AndroidDevicePushNotificationRegistration"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAndroidDevicePushNotificationRegistrationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAndroidDevicePushNotificationRegistrationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AndroidDevicePushNotificationRegistrationResult* outResult = new ClientModels::AndroidDevicePushNotificationRegistrationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::AttributeInstall(
    ClientModels::AttributeInstallRequest& request,
    ProcessApiCallback<ClientModels::AttributeInstallResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AttributeInstall"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAttributeInstallResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAttributeInstallResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AttributeInstallResult* outResult = new ClientModels::AttributeInstallResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        // Modify advertisingIdType:  Prevents us from sending the id multiple times, and allows automated tests to determine id was sent successfully
        PlayFabSettings::playFabSettings->advertisingIdType += "_Successful";

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AttributeInstallResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AttributeInstallResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::CancelTrade(
    ClientModels::CancelTradeRequest& request,
    ProcessApiCallback<ClientModels::CancelTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/CancelTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnCancelTradeResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnCancelTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::CancelTradeResponse* outResult = new ClientModels::CancelTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::CancelTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::CancelTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ConfirmPurchase(
    ClientModels::ConfirmPurchaseRequest& request,
    ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ConfirmPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConfirmPurchaseResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnConfirmPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ConfirmPurchaseResult* outResult = new ClientModels::ConfirmPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ConfirmPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ConfirmPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ConsumeItem(
    ClientModels::ConsumeItemRequest& request,
    ProcessApiCallback<ClientModels::ConsumeItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ConsumeItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConsumeItemResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnConsumeItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ConsumeItemResult* outResult = new ClientModels::ConsumeItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ConsumeItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ConsumeItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::CreateSharedGroup(
    ClientModels::CreateSharedGroupRequest& request,
    ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/CreateSharedGroup"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnCreateSharedGroupResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnCreateSharedGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::CreateSharedGroupResult* outResult = new ClientModels::CreateSharedGroupResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::CreateSharedGroupResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::CreateSharedGroupResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ExecuteCloudScript(
    ClientModels::ExecuteCloudScriptRequest& request,
    ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ExecuteCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnExecuteCloudScriptResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnExecuteCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ExecuteCloudScriptResult* outResult = new ClientModels::ExecuteCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ExecuteCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetAccountInfo(
    ClientModels::GetAccountInfoRequest& request,
    ProcessApiCallback<ClientModels::GetAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetAccountInfoResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetAccountInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetAccountInfoResult* outResult = new ClientModels::GetAccountInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetAccountInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetAllUsersCharacters(
    ClientModels::ListUsersCharactersRequest& request,
    ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetAllUsersCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetAllUsersCharactersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetAllUsersCharactersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ListUsersCharactersResult* outResult = new ClientModels::ListUsersCharactersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ListUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ListUsersCharactersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCatalogItems(
    ClientModels::GetCatalogItemsRequest& request,
    ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCatalogItemsResult* outResult = new ClientModels::GetCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterData(
    ClientModels::GetCharacterDataRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterDataResult* outResult = new ClientModels::GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterInventory(
    ClientModels::GetCharacterInventoryRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterInventoryResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterInventoryResult* outResult = new ClientModels::GetCharacterInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterLeaderboard(
    ClientModels::GetCharacterLeaderboardRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterLeaderboardResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterLeaderboardResult* outResult = new ClientModels::GetCharacterLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterReadOnlyData(
    ClientModels::GetCharacterDataRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterDataResult* outResult = new ClientModels::GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCharacterStatistics(
    ClientModels::GetCharacterStatisticsRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterStatisticsResult* outResult = new ClientModels::GetCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetContentDownloadUrl(
    ClientModels::GetContentDownloadUrlRequest& request,
    ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetContentDownloadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetContentDownloadUrlResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetContentDownloadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetContentDownloadUrlResult* outResult = new ClientModels::GetContentDownloadUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetContentDownloadUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetCurrentGames(
    ClientModels::CurrentGamesRequest& request,
    ProcessApiCallback<ClientModels::CurrentGamesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCurrentGames"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCurrentGamesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCurrentGamesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::CurrentGamesResult* outResult = new ClientModels::CurrentGamesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::CurrentGamesResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::CurrentGamesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetFriendLeaderboard(
    ClientModels::GetFriendLeaderboardRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetFriendLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardResult* outResult = new ClientModels::GetLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetFriendLeaderboardAroundPlayer(
    ClientModels::GetFriendLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetFriendLeaderboardAroundPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardAroundPlayerResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendLeaderboardAroundPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetFriendLeaderboardAroundPlayerResult* outResult = new ClientModels::GetFriendLeaderboardAroundPlayerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetFriendsList(
    ClientModels::GetFriendsListRequest& request,
    ProcessApiCallback<ClientModels::GetFriendsListResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetFriendsList"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendsListResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendsListResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetFriendsListResult* outResult = new ClientModels::GetFriendsListResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetFriendsListResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetFriendsListResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetGameServerRegions(
    ClientModels::GameServerRegionsRequest& request,
    ProcessApiCallback<ClientModels::GameServerRegionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetGameServerRegions"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetGameServerRegionsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetGameServerRegionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GameServerRegionsResult* outResult = new ClientModels::GameServerRegionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GameServerRegionsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GameServerRegionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboard(
    ClientModels::GetLeaderboardRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardResult* outResult = new ClientModels::GetLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboardAroundCharacter(
    ClientModels::GetLeaderboardAroundCharacterRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetLeaderboardAroundCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundCharacterResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardAroundCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardAroundCharacterResult* outResult = new ClientModels::GetLeaderboardAroundCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboardAroundPlayer(
    ClientModels::GetLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetLeaderboardAroundPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundPlayerResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardAroundPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardAroundPlayerResult* outResult = new ClientModels::GetLeaderboardAroundPlayerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetLeaderboardForUserCharacters(
    ClientModels::GetLeaderboardForUsersCharactersRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetLeaderboardForUserCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardForUserCharactersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardForUserCharactersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardForUsersCharactersResult* outResult = new ClientModels::GetLeaderboardForUsersCharactersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPhotonAuthenticationToken(
    ClientModels::GetPhotonAuthenticationTokenRequest& request,
    ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPhotonAuthenticationToken"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPhotonAuthenticationTokenResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPhotonAuthenticationTokenResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPhotonAuthenticationTokenResult* outResult = new ClientModels::GetPhotonAuthenticationTokenResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerCombinedInfo(
    ClientModels::GetPlayerCombinedInfoRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerCombinedInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerCombinedInfoResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerCombinedInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerCombinedInfoResult* outResult = new ClientModels::GetPlayerCombinedInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerProfile(
    ClientModels::GetPlayerProfileRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerProfile"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerProfileResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerProfileResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerProfileResult* outResult = new ClientModels::GetPlayerProfileResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerProfileResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerProfileResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerSegments(

    ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerSegments"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetPlayerSegmentsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerSegmentsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerSegmentsResult* outResult = new ClientModels::GetPlayerSegmentsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerSegmentsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerStatistics(
    ClientModels::GetPlayerStatisticsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerStatisticsResult* outResult = new ClientModels::GetPlayerStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerStatisticVersions(
    ClientModels::GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerStatisticVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticVersionsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerStatisticVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerStatisticVersionsResult* outResult = new ClientModels::GetPlayerStatisticVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerTags(
    ClientModels::GetPlayerTagsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerTags"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTagsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerTagsResult* outResult = new ClientModels::GetPlayerTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayerTrades(
    ClientModels::GetPlayerTradesRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerTrades"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTradesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerTradesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerTradesResponse* outResult = new ClientModels::GetPlayerTradesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerTradesResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerTradesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromFacebookIDs(
    ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromFacebookIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromFacebookIDsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromFacebookIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromFacebookIDsResult* outResult = new ClientModels::GetPlayFabIDsFromFacebookIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromGameCenterIDs(
    ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromGameCenterIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGameCenterIDsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromGameCenterIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromGameCenterIDsResult* outResult = new ClientModels::GetPlayFabIDsFromGameCenterIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromGenericIDs(
    ClientModels::GetPlayFabIDsFromGenericIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromGenericIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGenericIDsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromGenericIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromGenericIDsResult* outResult = new ClientModels::GetPlayFabIDsFromGenericIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromGoogleIDs(
    ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromGoogleIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGoogleIDsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromGoogleIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromGoogleIDsResult* outResult = new ClientModels::GetPlayFabIDsFromGoogleIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromKongregateIDs(
    ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromKongregateIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromKongregateIDsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromKongregateIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromKongregateIDsResult* outResult = new ClientModels::GetPlayFabIDsFromKongregateIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromSteamIDs(
    ClientModels::GetPlayFabIDsFromSteamIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromSteamIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromSteamIDsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromSteamIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromSteamIDsResult* outResult = new ClientModels::GetPlayFabIDsFromSteamIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPlayFabIDsFromTwitchIDs(
    ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromTwitchIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromTwitchIDsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromTwitchIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromTwitchIDsResult* outResult = new ClientModels::GetPlayFabIDsFromTwitchIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPublisherData(
    ClientModels::GetPublisherDataRequest& request,
    ProcessApiCallback<ClientModels::GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPublisherDataResult* outResult = new ClientModels::GetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetPurchase(
    ClientModels::GetPurchaseRequest& request,
    ProcessApiCallback<ClientModels::GetPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPurchaseResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPurchaseResult* outResult = new ClientModels::GetPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetSharedGroupData(
    ClientModels::GetSharedGroupDataRequest& request,
    ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetSharedGroupDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetSharedGroupDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetSharedGroupDataResult* outResult = new ClientModels::GetSharedGroupDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetSharedGroupDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetStoreItems(
    ClientModels::GetStoreItemsRequest& request,
    ProcessApiCallback<ClientModels::GetStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetStoreItemsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetStoreItemsResult* outResult = new ClientModels::GetStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetTime(

    ProcessApiCallback<ClientModels::GetTimeResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTime"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetTimeResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTimeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTimeResult* outResult = new ClientModels::GetTimeResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTimeResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTimeResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetTitleData(
    ClientModels::GetTitleDataRequest& request,
    ProcessApiCallback<ClientModels::GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTitleDataResult* outResult = new ClientModels::GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetTitleNews(
    ClientModels::GetTitleNewsRequest& request,
    ProcessApiCallback<ClientModels::GetTitleNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTitleNews"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTitleNewsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTitleNewsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTitleNewsResult* outResult = new ClientModels::GetTitleNewsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTitleNewsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTitleNewsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetTitlePublicKey(
    ClientModels::GetTitlePublicKeyRequest& request,
    ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTitlePublicKey"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetTitlePublicKeyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTitlePublicKeyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTitlePublicKeyResult* outResult = new ClientModels::GetTitlePublicKeyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTitlePublicKeyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetTradeStatus(
    ClientModels::GetTradeStatusRequest& request,
    ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTradeStatus"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTradeStatusResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTradeStatusResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTradeStatusResponse* outResult = new ClientModels::GetTradeStatusResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTradeStatusResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTradeStatusResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserData(
    ClientModels::GetUserDataRequest& request,
    ProcessApiCallback<ClientModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserDataResult* outResult = new ClientModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserInventory(

    ProcessApiCallback<ClientModels::GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetUserInventoryResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserInventoryResult* outResult = new ClientModels::GetUserInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserPublisherData(
    ClientModels::GetUserDataRequest& request,
    ProcessApiCallback<ClientModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserDataResult* outResult = new ClientModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserPublisherReadOnlyData(
    ClientModels::GetUserDataRequest& request,
    ProcessApiCallback<ClientModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserDataResult* outResult = new ClientModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetUserReadOnlyData(
    ClientModels::GetUserDataRequest& request,
    ProcessApiCallback<ClientModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserDataResult* outResult = new ClientModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GetWindowsHelloChallenge(
    ClientModels::GetWindowsHelloChallengeRequest& request,
    ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetWindowsHelloChallenge"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetWindowsHelloChallengeResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetWindowsHelloChallengeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetWindowsHelloChallengeResponse* outResult = new ClientModels::GetWindowsHelloChallengeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::GrantCharacterToUser(
    ClientModels::GrantCharacterToUserRequest& request,
    ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GrantCharacterToUser"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGrantCharacterToUserResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGrantCharacterToUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GrantCharacterToUserResult* outResult = new ClientModels::GrantCharacterToUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GrantCharacterToUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GrantCharacterToUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkAndroidDeviceID(
    ClientModels::LinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkAndroidDeviceIDResult* outResult = new ClientModels::LinkAndroidDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkCustomID(
    ClientModels::LinkCustomIDRequest& request,
    ProcessApiCallback<ClientModels::LinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkCustomID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkCustomIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkCustomIDResult* outResult = new ClientModels::LinkCustomIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkCustomIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkCustomIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkFacebookAccount(
    ClientModels::LinkFacebookAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkFacebookAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkFacebookAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkFacebookAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkFacebookAccountResult* outResult = new ClientModels::LinkFacebookAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkFacebookAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkFacebookAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkGameCenterAccount(
    ClientModels::LinkGameCenterAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkGameCenterAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkGameCenterAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkGameCenterAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkGameCenterAccountResult* outResult = new ClientModels::LinkGameCenterAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkGameCenterAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkGoogleAccount(
    ClientModels::LinkGoogleAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkGoogleAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkGoogleAccountResult* outResult = new ClientModels::LinkGoogleAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkGoogleAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkGoogleAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkIOSDeviceID(
    ClientModels::LinkIOSDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkIOSDeviceIDResult* outResult = new ClientModels::LinkIOSDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkKongregate(
    ClientModels::LinkKongregateAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkKongregate"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkKongregateResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkKongregateAccountResult* outResult = new ClientModels::LinkKongregateAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkKongregateAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkKongregateAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkSteamAccount(
    ClientModels::LinkSteamAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkSteamAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkSteamAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkSteamAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkSteamAccountResult* outResult = new ClientModels::LinkSteamAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkSteamAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkSteamAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkTwitch(
    ClientModels::LinkTwitchAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkTwitch"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkTwitchResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkTwitchResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkTwitchAccountResult* outResult = new ClientModels::LinkTwitchAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkTwitchAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkTwitchAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LinkWindowsHello(
    ClientModels::LinkWindowsHelloAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkWindowsHello"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkWindowsHelloResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkWindowsHelloResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkWindowsHelloAccountResponse* outResult = new ClientModels::LinkWindowsHelloAccountResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithAndroidDeviceID(
    ClientModels::LoginWithAndroidDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithCustomID(
    ClientModels::LoginWithCustomIDRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithCustomID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithCustomIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithEmailAddress(
    ClientModels::LoginWithEmailAddressRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithEmailAddress"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithEmailAddressResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithEmailAddressResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithFacebook(
    ClientModels::LoginWithFacebookRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithFacebook"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithFacebookResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithFacebookResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithGameCenter(
    ClientModels::LoginWithGameCenterRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithGameCenter"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithGameCenterResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithGameCenterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithGoogleAccount(
    ClientModels::LoginWithGoogleAccountRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithGoogleAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithIOSDeviceID(
    ClientModels::LoginWithIOSDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithKongregate(
    ClientModels::LoginWithKongregateRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithKongregate"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithKongregateResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithPlayFab(
    ClientModels::LoginWithPlayFabRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithPlayFab"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithPlayFabResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithPlayFabResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithSteam(
    ClientModels::LoginWithSteamRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithSteam"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithSteamResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithSteamResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithTwitch(
    ClientModels::LoginWithTwitchRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithTwitch"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithTwitchResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithTwitchResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::LoginWithWindowsHello(
    ClientModels::LoginWithWindowsHelloRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithWindowsHello"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithWindowsHelloResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithWindowsHelloResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::Matchmake(
    ClientModels::MatchmakeRequest& request,
    ProcessApiCallback<ClientModels::MatchmakeResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/Matchmake"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnMatchmakeResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnMatchmakeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::MatchmakeResult* outResult = new ClientModels::MatchmakeResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::MatchmakeResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::MatchmakeResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::OpenTrade(
    ClientModels::OpenTradeRequest& request,
    ProcessApiCallback<ClientModels::OpenTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/OpenTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnOpenTradeResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnOpenTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::OpenTradeResponse* outResult = new ClientModels::OpenTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::OpenTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::OpenTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::PayForPurchase(
    ClientModels::PayForPurchaseRequest& request,
    ProcessApiCallback<ClientModels::PayForPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/PayForPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnPayForPurchaseResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnPayForPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::PayForPurchaseResult* outResult = new ClientModels::PayForPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::PayForPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::PayForPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::PurchaseItem(
    ClientModels::PurchaseItemRequest& request,
    ProcessApiCallback<ClientModels::PurchaseItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/PurchaseItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnPurchaseItemResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnPurchaseItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::PurchaseItemResult* outResult = new ClientModels::PurchaseItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::PurchaseItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::PurchaseItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RedeemCoupon(
    ClientModels::RedeemCouponRequest& request,
    ProcessApiCallback<ClientModels::RedeemCouponResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RedeemCoupon"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRedeemCouponResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRedeemCouponResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RedeemCouponResult* outResult = new ClientModels::RedeemCouponResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RedeemCouponResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RedeemCouponResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RegisterForIOSPushNotification(
    ClientModels::RegisterForIOSPushNotificationRequest& request,
    ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RegisterForIOSPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRegisterForIOSPushNotificationResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRegisterForIOSPushNotificationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RegisterForIOSPushNotificationResult* outResult = new ClientModels::RegisterForIOSPushNotificationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RegisterPlayFabUser(
    ClientModels::RegisterPlayFabUserRequest& request,
    ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RegisterPlayFabUser"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRegisterPlayFabUserResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRegisterPlayFabUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RegisterPlayFabUserResult* outResult = new ClientModels::RegisterPlayFabUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RegisterPlayFabUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RegisterWithWindowsHello(
    ClientModels::RegisterWithWindowsHelloRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RegisterWithWindowsHello"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRegisterWithWindowsHelloResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRegisterWithWindowsHelloResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RemoveFriend(
    ClientModels::RemoveFriendRequest& request,
    ProcessApiCallback<ClientModels::RemoveFriendResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RemoveFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveFriendResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRemoveFriendResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RemoveFriendResult* outResult = new ClientModels::RemoveFriendResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RemoveFriendResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RemoveFriendResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RemoveGenericID(
    ClientModels::RemoveGenericIDRequest& request,
    ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RemoveGenericID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveGenericIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRemoveGenericIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RemoveGenericIDResult* outResult = new ClientModels::RemoveGenericIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RemoveGenericIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RemoveGenericIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RemoveSharedGroupMembers(
    ClientModels::RemoveSharedGroupMembersRequest& request,
    ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RemoveSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveSharedGroupMembersResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRemoveSharedGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RemoveSharedGroupMembersResult* outResult = new ClientModels::RemoveSharedGroupMembersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ReportPlayer(
    ClientModels::ReportPlayerClientRequest& request,
    ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ReportPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnReportPlayerResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnReportPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ReportPlayerClientResult* outResult = new ClientModels::ReportPlayerClientResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ReportPlayerClientResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ReportPlayerClientResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::RestoreIOSPurchases(
    ClientModels::RestoreIOSPurchasesRequest& request,
    ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RestoreIOSPurchases"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRestoreIOSPurchasesResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRestoreIOSPurchasesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RestoreIOSPurchasesResult* outResult = new ClientModels::RestoreIOSPurchasesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::SendAccountRecoveryEmail(
    ClientModels::SendAccountRecoveryEmailRequest& request,
    ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/SendAccountRecoveryEmail"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSendAccountRecoveryEmailResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnSendAccountRecoveryEmailResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::SendAccountRecoveryEmailResult* outResult = new ClientModels::SendAccountRecoveryEmailResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::SetFriendTags(
    ClientModels::SetFriendTagsRequest& request,
    ProcessApiCallback<ClientModels::SetFriendTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/SetFriendTags"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSetFriendTagsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnSetFriendTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::SetFriendTagsResult* outResult = new ClientModels::SetFriendTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::SetFriendTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::SetFriendTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::SetPlayerSecret(
    ClientModels::SetPlayerSecretRequest& request,
    ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/SetPlayerSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSetPlayerSecretResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnSetPlayerSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::SetPlayerSecretResult* outResult = new ClientModels::SetPlayerSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::SetPlayerSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::SetPlayerSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::StartGame(
    ClientModels::StartGameRequest& request,
    ProcessApiCallback<ClientModels::StartGameResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/StartGame"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnStartGameResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnStartGameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::StartGameResult* outResult = new ClientModels::StartGameResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::StartGameResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::StartGameResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::StartPurchase(
    ClientModels::StartPurchaseRequest& request,
    ProcessApiCallback<ClientModels::StartPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/StartPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnStartPurchaseResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnStartPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::StartPurchaseResult* outResult = new ClientModels::StartPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::StartPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::StartPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::SubtractUserVirtualCurrency(
    ClientModels::SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ModifyUserVirtualCurrencyResult* outResult = new ClientModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkAndroidDeviceID(
    ClientModels::UnlinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkAndroidDeviceIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkAndroidDeviceIDResult* outResult = new ClientModels::UnlinkAndroidDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkCustomID(
    ClientModels::UnlinkCustomIDRequest& request,
    ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkCustomID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkCustomIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkCustomIDResult* outResult = new ClientModels::UnlinkCustomIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkCustomIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkCustomIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkFacebookAccount(

    ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkFacebookAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkFacebookAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkFacebookAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkFacebookAccountResult* outResult = new ClientModels::UnlinkFacebookAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkGameCenterAccount(

    ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkGameCenterAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkGameCenterAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkGameCenterAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkGameCenterAccountResult* outResult = new ClientModels::UnlinkGameCenterAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkGoogleAccount(

    ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkGoogleAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkGoogleAccountResult* outResult = new ClientModels::UnlinkGoogleAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkIOSDeviceID(
    ClientModels::UnlinkIOSDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkIOSDeviceIDResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkIOSDeviceIDResult* outResult = new ClientModels::UnlinkIOSDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkKongregate(

    ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkKongregate"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkKongregateResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkKongregateAccountResult* outResult = new ClientModels::UnlinkKongregateAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkSteamAccount(

    ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkSteamAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkSteamAccountResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkSteamAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkSteamAccountResult* outResult = new ClientModels::UnlinkSteamAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkSteamAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkTwitch(

    ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkTwitch"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkTwitchResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkTwitchResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkTwitchAccountResult* outResult = new ClientModels::UnlinkTwitchAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlinkWindowsHello(
    ClientModels::UnlinkWindowsHelloAccountRequest& request,
    ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkWindowsHello"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkWindowsHelloResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkWindowsHelloResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkWindowsHelloAccountResponse* outResult = new ClientModels::UnlinkWindowsHelloAccountResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlockContainerInstance(
    ClientModels::UnlockContainerInstanceRequest& request,
    ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlockContainerInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerInstanceResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlockContainerInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlockContainerItemResult* outResult = new ClientModels::UnlockContainerItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlockContainerItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UnlockContainerItem(
    ClientModels::UnlockContainerItemRequest& request,
    ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlockContainerItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerItemResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlockContainerItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlockContainerItemResult* outResult = new ClientModels::UnlockContainerItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlockContainerItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateAvatarUrl(
    ClientModels::UpdateAvatarUrlRequest& request,
    ProcessApiCallback<ClientModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateAvatarUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateAvatarUrlResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateAvatarUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::EmptyResult* outResult = new ClientModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateCharacterData(
    ClientModels::UpdateCharacterDataRequest& request,
    ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateCharacterDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateCharacterDataResult* outResult = new ClientModels::UpdateCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateCharacterStatistics(
    ClientModels::UpdateCharacterStatisticsRequest& request,
    ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterStatisticsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateCharacterStatisticsResult* outResult = new ClientModels::UpdateCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdatePlayerStatistics(
    ClientModels::UpdatePlayerStatisticsRequest& request,
    ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdatePlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticsResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdatePlayerStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdatePlayerStatisticsResult* outResult = new ClientModels::UpdatePlayerStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateSharedGroupData(
    ClientModels::UpdateSharedGroupDataRequest& request,
    ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateSharedGroupDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateSharedGroupDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateSharedGroupDataResult* outResult = new ClientModels::UpdateSharedGroupDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateUserData(
    ClientModels::UpdateUserDataRequest& request,
    ProcessApiCallback<ClientModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateUserDataResult* outResult = new ClientModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateUserPublisherData(
    ClientModels::UpdateUserDataRequest& request,
    ProcessApiCallback<ClientModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateUserDataResult* outResult = new ClientModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::UpdateUserTitleDisplayName(
    ClientModels::UpdateUserTitleDisplayNameRequest& request,
    ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateUserTitleDisplayName"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserTitleDisplayNameResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserTitleDisplayNameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateUserTitleDisplayNameResult* outResult = new ClientModels::UpdateUserTitleDisplayNameResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ValidateAmazonIAPReceipt(
    ClientModels::ValidateAmazonReceiptRequest& request,
    ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ValidateAmazonIAPReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateAmazonIAPReceiptResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateAmazonIAPReceiptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ValidateAmazonReceiptResult* outResult = new ClientModels::ValidateAmazonReceiptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ValidateGooglePlayPurchase(
    ClientModels::ValidateGooglePlayPurchaseRequest& request,
    ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ValidateGooglePlayPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateGooglePlayPurchaseResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateGooglePlayPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ValidateGooglePlayPurchaseResult* outResult = new ClientModels::ValidateGooglePlayPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ValidateIOSReceipt(
    ClientModels::ValidateIOSReceiptRequest& request,
    ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ValidateIOSReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateIOSReceiptResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateIOSReceiptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ValidateIOSReceiptResult* outResult = new ClientModels::ValidateIOSReceiptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ValidateIOSReceiptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::ValidateWindowsStoreReceipt(
    ClientModels::ValidateWindowsReceiptRequest& request,
    ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ValidateWindowsStoreReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateWindowsStoreReceiptResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateWindowsStoreReceiptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ValidateWindowsReceiptResult* outResult = new ClientModels::ValidateWindowsReceiptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::WriteCharacterEvent(
    ClientModels::WriteClientCharacterEventRequest& request,
    ProcessApiCallback<ClientModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/WriteCharacterEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWriteCharacterEventResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnWriteCharacterEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::WriteEventResponse* outResult = new ClientModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::WritePlayerEvent(
    ClientModels::WriteClientPlayerEventRequest& request,
    ProcessApiCallback<ClientModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/WritePlayerEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWritePlayerEventResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnWritePlayerEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::WriteEventResponse* outResult = new ClientModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

void PlayFabClientApi::WriteTitleEvent(
    ClientModels::WriteTitleEventRequest& request,
    ProcessApiCallback<ClientModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/WriteTitleEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWriteTitleEventResult);
    PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnWriteTitleEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::WriteEventResponse* outResult = new ClientModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }
        delete outResult;
        delete request;
    }
}

