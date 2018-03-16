
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk/PlayFabCombo_ServerBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_ServerSysComponent
        : public AZ::Component
        , protected PlayFabCombo_ServerRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabCombo_ServerSysComponent, "{525A86F9-CFF4-4868-A55F-24F5E76823CD}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabCombo_ServerRequestBus interface implementation

        // ------------ Generated Api calls
        void AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddFriend(ServerModels::AddFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddPlayerTag(ServerModels::AddPlayerTagRequest& request, ProcessApiCallback<ServerModels::AddPlayerTagResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeregisterGame(ServerModels::DeregisterGameRequest& request, ProcessApiCallback<ServerModels::DeregisterGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request, ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request, ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetAllSegments(ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFriendLeaderboard(ServerModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFriendsList(ServerModels::GetFriendsListRequest& request, ProcessApiCallback<ServerModels::GetFriendsListResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerProfile(ServerModels::GetPlayerProfileRequest& request, ProcessApiCallback<ServerModels::GetPlayerProfileResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerTags(ServerModels::GetPlayerTagsRequest& request, ProcessApiCallback<ServerModels::GetPlayerTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTime(ProcessApiCallback<ServerModels::GetTimeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserBans(ServerModels::GetUserBansRequest& request, ProcessApiCallback<ServerModels::GetUserBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request, ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RegisterGame(ServerModels::RegisterGameRequest& request, ProcessApiCallback<ServerModels::RegisterGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveFriend(ServerModels::RemoveFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemovePlayerTag(ServerModels::RemovePlayerTagRequest& request, ProcessApiCallback<ServerModels::RemovePlayerTagResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RevokeBans(ServerModels::RevokeBansRequest& request, ProcessApiCallback<ServerModels::RevokeBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RevokeInventoryItems(ServerModels::RevokeInventoryItemsRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SendCustomAccountRecoveryEmail(ServerModels::SendCustomAccountRecoveryEmailRequest& request, ProcessApiCallback<ServerModels::SendCustomAccountRecoveryEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SendEmailFromTemplate(ServerModels::SendEmailFromTemplateRequest& request, ProcessApiCallback<ServerModels::SendEmailFromTemplateResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetFriendTags(ServerModels::SetFriendTagsRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request, ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WriteTitleEvent(ServerModels::WriteTitleEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
