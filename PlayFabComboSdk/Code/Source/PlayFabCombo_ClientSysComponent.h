
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk/PlayFabCombo_ClientBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_ClientSysComponent
        : public AZ::Component
        , protected PlayFabCombo_ClientRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabCombo_ClientSysComponent, "{525A86F9-CFF4-4868-A55F-24F5E76823CB}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabCombo_ClientRequestBus interface implementation

        // Public, Client-Specific
        bool IsClientLoggedIn() override;

        // ------------ Generated Api calls
        void AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddGenericID(ClientModels::AddGenericIDRequest& request, ProcessApiCallback<ClientModels::AddGenericIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddOrUpdateContactEmail(ClientModels::AddOrUpdateContactEmailRequest& request, ProcessApiCallback<ClientModels::AddOrUpdateContactEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPaymentToken(ClientModels::GetPaymentTokenRequest& request, ProcessApiCallback<ClientModels::GetPaymentTokenResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request, ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerSegments(ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerTags(ClientModels::GetPlayerTagsRequest& request, ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromNintendoSwitchDeviceIds(ClientModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTime(ProcessApiCallback<ClientModels::GetTimeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request, ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserInventory(ProcessApiCallback<ClientModels::GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request, ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkNintendoSwitchDeviceId(ClientModels::LinkNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::LinkNintendoSwitchDeviceIdResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkTwitch(ClientModels::LinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithNintendoSwitchDeviceId(ClientModels::LoginWithNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveContactEmail(ProcessApiCallback<ClientModels::RemoveContactEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveGenericID(ClientModels::RemoveGenericIDRequest& request, ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ReportDeviceInfo(ClientModels::DeviceInfoRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request, ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkFacebookAccount(ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkGameCenterAccount(ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkGoogleAccount(ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkKongregate(ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkNintendoSwitchDeviceId(ClientModels::UnlinkNintendoSwitchDeviceIdRequest& request, ProcessApiCallback<ClientModels::UnlinkNintendoSwitchDeviceIdResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkSteamAccount(ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkTwitch(ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WriteTitleEvent(ClientModels::WriteTitleEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
