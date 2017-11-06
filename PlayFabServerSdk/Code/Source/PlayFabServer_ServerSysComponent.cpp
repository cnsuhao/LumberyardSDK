
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServer_ServerSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabServerApi.h"

namespace PlayFabServerSdk
{
    void PlayFabServer_ServerSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServer_ServerSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServer_ServerSysComponent>("PlayFabServer_Server", "Provides access to the Server API within the PlayFab Server SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServer_ServerSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServer_ServerService"));
    }

    void PlayFabServer_ServerSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServer_ServerService"));
    }

    void PlayFabServer_ServerSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServer_ServerSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServer_ServerSysComponent::Init()
    {
    }

    void PlayFabServer_ServerSysComponent::Activate()
    {
        PlayFabServer_ServerRequestBus::Handler::BusConnect();
    }

    void PlayFabServer_ServerSysComponent::Deactivate()
    {
        PlayFabServer_ServerRequestBus::Handler::BusDisconnect();
    }

    int PlayFabServer_ServerSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabServer_ServerSysComponent::AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::AddCharacterVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::AddFriend(ServerModels::AddFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::AddFriend(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::AddPlayerTag(ServerModels::AddPlayerTagRequest& request, ProcessApiCallback<ServerModels::AddPlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::AddPlayerTag(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::AddSharedGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::AuthenticateSessionTicket(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::AwardSteamAchievement(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::BanUsers(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::ConsumeItem(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::CreateSharedGroup(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::DeleteCharacterFromUser(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::DeleteSharedGroup(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::DeleteUsers(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::DeregisterGame(ServerModels::DeregisterGameRequest& request, ProcessApiCallback<ServerModels::DeregisterGameResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::DeregisterGame(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request, ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::EvaluateRandomResultTable(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request, ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::ExecuteCloudScript(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetAllSegments(ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetAllSegments(callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetAllUsersCharacters(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetCatalogItems(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetCharacterData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetCharacterInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetCharacterInventory(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetCharacterLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetCharacterReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetCharacterStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetContentDownloadUrl(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetFriendLeaderboard(ServerModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetFriendLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetFriendsList(ServerModels::GetFriendsListRequest& request, ProcessApiCallback<ServerModels::GetFriendsListResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetFriendsList(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetLeaderboardAroundCharacter(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetLeaderboardAroundUser(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetLeaderboardForUserCharacters(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayerCombinedInfo(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayerProfile(ServerModels::GetPlayerProfileRequest& request, ProcessApiCallback<ServerModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayerProfile(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayerSegments(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayersInSegment(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayerStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayerTags(ServerModels::GetPlayerTagsRequest& request, ProcessApiCallback<ServerModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayerTags(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayFabIDsFromFacebookIDs(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPlayFabIDsFromSteamIDs(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetRandomResultTables(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetSharedGroupData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetTime(ProcessApiCallback<ServerModels::GetTimeResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetTime(callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetTitleData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetTitleInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetTitleNews(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserAccountInfo(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserBans(ServerModels::GetUserBansRequest& request, ProcessApiCallback<ServerModels::GetUserBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserBans(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserInventory(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserPublisherInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GrantCharacterToUser(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GrantItemsToCharacter(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GrantItemsToUser(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::GrantItemsToUsers(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::ModifyItemUses(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::MoveItemToCharacterFromCharacter(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::MoveItemToCharacterFromUser(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::MoveItemToUserFromCharacter(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::NotifyMatchmakerPlayerLeft(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RedeemCoupon(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RedeemMatchmakerTicket(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request, ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RefreshGameServerInstanceHeartbeat(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RegisterGame(ServerModels::RegisterGameRequest& request, ProcessApiCallback<ServerModels::RegisterGameResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RegisterGame(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RemoveFriend(ServerModels::RemoveFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RemoveFriend(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RemovePlayerTag(ServerModels::RemovePlayerTagRequest& request, ProcessApiCallback<ServerModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RemovePlayerTag(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RemoveSharedGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::ReportPlayer(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RevokeAllBansForUser(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RevokeBans(ServerModels::RevokeBansRequest& request, ProcessApiCallback<ServerModels::RevokeBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RevokeBans(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::RevokeInventoryItem(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SendCustomAccountRecoveryEmail(ServerModels::SendCustomAccountRecoveryEmailRequest& request, ProcessApiCallback<ServerModels::SendCustomAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SendCustomAccountRecoveryEmail(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SendEmailFromTemplate(ServerModels::SendEmailFromTemplateRequest& request, ProcessApiCallback<ServerModels::SendEmailFromTemplateResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SendEmailFromTemplate(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SendPushNotification(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SetFriendTags(ServerModels::SetFriendTagsRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SetFriendTags(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SetGameServerInstanceData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SetGameServerInstanceState(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SetGameServerInstanceTags(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request, ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SetPlayerSecret(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SetPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SetTitleData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SetTitleInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SubtractCharacterVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UnlockContainerInstance(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UnlockContainerItem(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateAvatarUrl(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateBans(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateCharacterData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateCharacterInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateCharacterReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateCharacterStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdatePlayerStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateSharedGroupData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateUserData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateUserInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateUserInventoryItemCustomData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateUserPublisherInternalData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::UpdateUserReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::WriteCharacterEvent(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::WritePlayerEvent(request, callback, errorCallback, customData);
    }
    void PlayFabServer_ServerSysComponent::WriteTitleEvent(ServerModels::WriteTitleEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabServerApi::WriteTitleEvent(request, callback, errorCallback, customData);
    }
}
