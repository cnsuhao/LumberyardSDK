
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_ClientSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabClientApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_ClientSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_ClientSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_ClientSysComponent>("PlayFabCombo_Client", "Provides access to the Client API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_ClientSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_ClientService"));
    }

    void PlayFabCombo_ClientSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_ClientService"));
    }

    void PlayFabCombo_ClientSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_ClientSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_ClientSysComponent::Init()
    {
    }

    void PlayFabCombo_ClientSysComponent::Activate()
    {
        PlayFabCombo_ClientRequestBus::Handler::BusConnect();
    }

    void PlayFabCombo_ClientSysComponent::Deactivate()
    {
        PlayFabCombo_ClientRequestBus::Handler::BusDisconnect();
    }

    int PlayFabCombo_ClientSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // Client-Specific
    bool PlayFabCombo_ClientSysComponent::IsClientLoggedIn()
    {
        return PlayFabClientApi::IsClientLoggedIn();
    }

    // ------------ Generated API call wrappers
    void PlayFabCombo_ClientSysComponent::GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPhotonAuthenticationToken(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request, ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTitlePublicKey(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request, ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetWindowsHelloChallenge(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithAndroidDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithCustomID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithEmailAddress(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithFacebook(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithGameCenter(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithGoogleAccount(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithIOSDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithKongregate(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithPlayFab(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithSteam(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithTwitch(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithWindowsHello(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RegisterPlayFabUser(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RegisterWithWindowsHello(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request, ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::SetPlayerSecret(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::AddGenericID(ClientModels::AddGenericIDRequest& request, ProcessApiCallback<ClientModels::AddGenericIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddGenericID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddUsernamePassword(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetAccountInfo(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerCombinedInfo(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request, ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerProfile(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromFacebookIDs(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromGameCenterIDs(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromGenericIDs(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromGoogleIDs(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromKongregateIDs(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromSteamIDs(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromTwitchIDs(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkAndroidDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkCustomID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkFacebookAccount(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkGameCenterAccount(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkGoogleAccount(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkIOSDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkKongregate(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkSteamAccount(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkTwitch(ClientModels::LinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkTwitch(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkWindowsHello(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::RemoveGenericID(ClientModels::RemoveGenericIDRequest& request, ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RemoveGenericID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ReportPlayer(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::SendAccountRecoveryEmail(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkAndroidDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkCustomID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkFacebookAccount(ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkFacebookAccount(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkGameCenterAccount(ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkGameCenterAccount(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkGoogleAccount(ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkGoogleAccount(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkIOSDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkKongregate(ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkKongregate(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkSteamAccount(ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkSteamAccount(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkTwitch(ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkTwitch(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkWindowsHello(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateAvatarUrl(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateUserTitleDisplayName(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetFriendLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetFriendLeaderboardAroundPlayer(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetLeaderboardAroundPlayer(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdatePlayerStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateUserData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCatalogItems(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetStoreItems(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetTime(ProcessApiCallback<ClientModels::GetTimeResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTime(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTitleData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTitleNews(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ConfirmPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ConsumeItem(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterInventory(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetUserInventory(ProcessApiCallback<ClientModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserInventory(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::PayForPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::PurchaseItem(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RedeemCoupon(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::StartPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlockContainerInstance(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlockContainerItem(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddFriend(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetFriendsList(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RemoveFriend(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::SetFriendTags(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCurrentGames(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetGameServerRegions(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::Matchmake(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::StartGame(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::WriteCharacterEvent(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::WritePlayerEvent(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::WriteTitleEvent(ClientModels::WriteTitleEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::WriteTitleEvent(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddSharedGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::CreateSharedGroup(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetSharedGroupData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RemoveSharedGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateSharedGroupData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ExecuteCloudScript(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetContentDownloadUrl(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetAllUsersCharacters(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetLeaderboardAroundCharacter(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetLeaderboardForUserCharacters(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GrantCharacterToUser(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateCharacterStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateCharacterData(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AcceptTrade(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::CancelTrade(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerTrades(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTradeStatus(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::OpenTrade(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AttributeInstall(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayerSegments(ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerSegments(callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::GetPlayerTags(ClientModels::GetPlayerTagsRequest& request, ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerTags(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AndroidDevicePushNotificationRegistration(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RegisterForIOSPushNotification(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RestoreIOSPurchases(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ValidateAmazonIAPReceipt(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ValidateGooglePlayPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ValidateIOSReceipt(request, callback, errorCallback, customData);
    }
    void PlayFabCombo_ClientSysComponent::ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ValidateWindowsStoreReceipt(request, callback, errorCallback, customData);
    }
}
