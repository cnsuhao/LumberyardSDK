#pragma once

#include "PlayFabBaseModel.h"
#include "aws/core/utils/json/JsonSerializer.h"

using namespace rapidjson;

namespace PlayFab
{
    namespace ServerModels
    {
        struct NameIdentifier : public PlayFabBaseModel
        {
            Aws::String Name;
            Aws::String Id;

            NameIdentifier() :
                PlayFabBaseModel(),
                Name(),
                Id()
            {}

            NameIdentifier(const NameIdentifier& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Id(src.Id)
            {}

            NameIdentifier(const rapidjson::Value& obj) : NameIdentifier()
            {
                readFromValue(obj);
            }

            ~NameIdentifier()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
                if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();

                return true;
            }
        };

        enum TaskInstanceStatus
        {
            TaskInstanceStatusSucceeded,
            TaskInstanceStatusStarting,
            TaskInstanceStatusInProgress,
            TaskInstanceStatusFailed,
            TaskInstanceStatusAborted,
            TaskInstanceStatusPending
        };

        inline void writeTaskInstanceStatusEnumJSON(TaskInstanceStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TaskInstanceStatusSucceeded: writer.String("Succeeded"); break;
            case TaskInstanceStatusStarting: writer.String("Starting"); break;
            case TaskInstanceStatusInProgress: writer.String("InProgress"); break;
            case TaskInstanceStatusFailed: writer.String("Failed"); break;
            case TaskInstanceStatusAborted: writer.String("Aborted"); break;
            case TaskInstanceStatusPending: writer.String("Pending"); break;

            }
        }

        inline TaskInstanceStatus readTaskInstanceStatusFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, TaskInstanceStatus> _TaskInstanceStatusMap;
            if (_TaskInstanceStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TaskInstanceStatusMap["Succeeded"] = TaskInstanceStatusSucceeded;
                _TaskInstanceStatusMap["Starting"] = TaskInstanceStatusStarting;
                _TaskInstanceStatusMap["InProgress"] = TaskInstanceStatusInProgress;
                _TaskInstanceStatusMap["Failed"] = TaskInstanceStatusFailed;
                _TaskInstanceStatusMap["Aborted"] = TaskInstanceStatusAborted;
                _TaskInstanceStatusMap["Pending"] = TaskInstanceStatusPending;

            }

            auto output = _TaskInstanceStatusMap.find(obj.GetString());
            if (output != _TaskInstanceStatusMap.end())
                return output->second;

            return TaskInstanceStatusSucceeded; // Basically critical fail
        }

        struct ActionsOnPlayersInSegmentTaskSummary : public PlayFabBaseModel
        {
            Aws::String TaskInstanceId;
            NameIdentifier* TaskIdentifier;
            time_t StartedAt;
            OptionalTime CompletedAt;
            Boxed<TaskInstanceStatus> Status;
            OptionalDouble PercentComplete;
            OptionalDouble EstimatedSecondsRemaining;
            Aws::String ScheduledByUserId;
            Aws::String ErrorMessage;
            OptionalBool ErrorWasFatal;
            OptionalInt32 TotalPlayersInSegment;
            OptionalInt32 TotalPlayersProcessed;

            ActionsOnPlayersInSegmentTaskSummary() :
                PlayFabBaseModel(),
                TaskInstanceId(),
                TaskIdentifier(nullptr),
                StartedAt(0),
                CompletedAt(),
                Status(),
                PercentComplete(),
                EstimatedSecondsRemaining(),
                ScheduledByUserId(),
                ErrorMessage(),
                ErrorWasFatal(),
                TotalPlayersInSegment(),
                TotalPlayersProcessed()
            {}

            ActionsOnPlayersInSegmentTaskSummary(const ActionsOnPlayersInSegmentTaskSummary& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : nullptr),
                StartedAt(src.StartedAt),
                CompletedAt(src.CompletedAt),
                Status(src.Status),
                PercentComplete(src.PercentComplete),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                ScheduledByUserId(src.ScheduledByUserId),
                ErrorMessage(src.ErrorMessage),
                ErrorWasFatal(src.ErrorWasFatal),
                TotalPlayersInSegment(src.TotalPlayersInSegment),
                TotalPlayersProcessed(src.TotalPlayersProcessed)
            {}

            ActionsOnPlayersInSegmentTaskSummary(const rapidjson::Value& obj) : ActionsOnPlayersInSegmentTaskSummary()
            {
                readFromValue(obj);
            }

            ~ActionsOnPlayersInSegmentTaskSummary()
            {
                if (TaskIdentifier != nullptr) delete TaskIdentifier;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TaskInstanceId.length() > 0) { writer.String("TaskInstanceId"); writer.String(TaskInstanceId.c_str()); }
                if (TaskIdentifier != nullptr) { writer.String("TaskIdentifier"); TaskIdentifier->writeJSON(writer); }
                writer.String("StartedAt"); writeDatetime(StartedAt, writer);
                if (CompletedAt.notNull()) { writer.String("CompletedAt"); writeDatetime(CompletedAt, writer); }
                if (Status.notNull()) { writer.String("Status"); writeTaskInstanceStatusEnumJSON(Status, writer); }
                if (PercentComplete.notNull()) { writer.String("PercentComplete"); writer.Double(PercentComplete); }
                if (EstimatedSecondsRemaining.notNull()) { writer.String("EstimatedSecondsRemaining"); writer.Double(EstimatedSecondsRemaining); }
                if (ScheduledByUserId.length() > 0) { writer.String("ScheduledByUserId"); writer.String(ScheduledByUserId.c_str()); }
                if (ErrorMessage.length() > 0) { writer.String("ErrorMessage"); writer.String(ErrorMessage.c_str()); }
                if (ErrorWasFatal.notNull()) { writer.String("ErrorWasFatal"); writer.Bool(ErrorWasFatal); }
                if (TotalPlayersInSegment.notNull()) { writer.String("TotalPlayersInSegment"); writer.Int(TotalPlayersInSegment); }
                if (TotalPlayersProcessed.notNull()) { writer.String("TotalPlayersProcessed"); writer.Int(TotalPlayersProcessed); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskInstanceId_member = obj.FindMember("TaskInstanceId");
                if (TaskInstanceId_member != obj.MemberEnd() && !TaskInstanceId_member->value.IsNull()) TaskInstanceId = TaskInstanceId_member->value.GetString();
                const Value::ConstMemberIterator TaskIdentifier_member = obj.FindMember("TaskIdentifier");
                if (TaskIdentifier_member != obj.MemberEnd() && !TaskIdentifier_member->value.IsNull()) TaskIdentifier = new NameIdentifier(TaskIdentifier_member->value);
                const Value::ConstMemberIterator StartedAt_member = obj.FindMember("StartedAt");
                if (StartedAt_member != obj.MemberEnd() && !StartedAt_member->value.IsNull()) StartedAt = readDatetime(StartedAt_member->value);
                const Value::ConstMemberIterator CompletedAt_member = obj.FindMember("CompletedAt");
                if (CompletedAt_member != obj.MemberEnd() && !CompletedAt_member->value.IsNull()) CompletedAt = readDatetime(CompletedAt_member->value);
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTaskInstanceStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator PercentComplete_member = obj.FindMember("PercentComplete");
                if (PercentComplete_member != obj.MemberEnd() && !PercentComplete_member->value.IsNull()) PercentComplete = PercentComplete_member->value.GetDouble();
                const Value::ConstMemberIterator EstimatedSecondsRemaining_member = obj.FindMember("EstimatedSecondsRemaining");
                if (EstimatedSecondsRemaining_member != obj.MemberEnd() && !EstimatedSecondsRemaining_member->value.IsNull()) EstimatedSecondsRemaining = EstimatedSecondsRemaining_member->value.GetDouble();
                const Value::ConstMemberIterator ScheduledByUserId_member = obj.FindMember("ScheduledByUserId");
                if (ScheduledByUserId_member != obj.MemberEnd() && !ScheduledByUserId_member->value.IsNull()) ScheduledByUserId = ScheduledByUserId_member->value.GetString();
                const Value::ConstMemberIterator ErrorMessage_member = obj.FindMember("ErrorMessage");
                if (ErrorMessage_member != obj.MemberEnd() && !ErrorMessage_member->value.IsNull()) ErrorMessage = ErrorMessage_member->value.GetString();
                const Value::ConstMemberIterator ErrorWasFatal_member = obj.FindMember("ErrorWasFatal");
                if (ErrorWasFatal_member != obj.MemberEnd() && !ErrorWasFatal_member->value.IsNull()) ErrorWasFatal = ErrorWasFatal_member->value.GetBool();
                const Value::ConstMemberIterator TotalPlayersInSegment_member = obj.FindMember("TotalPlayersInSegment");
                if (TotalPlayersInSegment_member != obj.MemberEnd() && !TotalPlayersInSegment_member->value.IsNull()) TotalPlayersInSegment = TotalPlayersInSegment_member->value.GetInt();
                const Value::ConstMemberIterator TotalPlayersProcessed_member = obj.FindMember("TotalPlayersProcessed");
                if (TotalPlayersProcessed_member != obj.MemberEnd() && !TotalPlayersProcessed_member->value.IsNull()) TotalPlayersProcessed = TotalPlayersProcessed_member->value.GetInt();

                return true;
            }
        };

        struct AdCampaignAttribution : public PlayFabBaseModel
        {
            Aws::String Platform;
            Aws::String CampaignId;
            time_t AttributedAt;

            AdCampaignAttribution() :
                PlayFabBaseModel(),
                Platform(),
                CampaignId(),
                AttributedAt(0)
            {}

            AdCampaignAttribution(const AdCampaignAttribution& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                CampaignId(src.CampaignId),
                AttributedAt(src.AttributedAt)
            {}

            AdCampaignAttribution(const rapidjson::Value& obj) : AdCampaignAttribution()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttribution()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.length() > 0) { writer.String("Platform"); writer.String(Platform.c_str()); }
                if (CampaignId.length() > 0) { writer.String("CampaignId"); writer.String(CampaignId.c_str()); }
                writer.String("AttributedAt"); writeDatetime(AttributedAt, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();
                const Value::ConstMemberIterator CampaignId_member = obj.FindMember("CampaignId");
                if (CampaignId_member != obj.MemberEnd() && !CampaignId_member->value.IsNull()) CampaignId = CampaignId_member->value.GetString();
                const Value::ConstMemberIterator AttributedAt_member = obj.FindMember("AttributedAt");
                if (AttributedAt_member != obj.MemberEnd() && !AttributedAt_member->value.IsNull()) AttributedAt = readDatetime(AttributedAt_member->value);

                return true;
            }
        };

        struct AdCampaignAttributionModel : public PlayFabBaseModel
        {
            Aws::String Platform;
            Aws::String CampaignId;
            time_t AttributedAt;

            AdCampaignAttributionModel() :
                PlayFabBaseModel(),
                Platform(),
                CampaignId(),
                AttributedAt(0)
            {}

            AdCampaignAttributionModel(const AdCampaignAttributionModel& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                CampaignId(src.CampaignId),
                AttributedAt(src.AttributedAt)
            {}

            AdCampaignAttributionModel(const rapidjson::Value& obj) : AdCampaignAttributionModel()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttributionModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.length() > 0) { writer.String("Platform"); writer.String(Platform.c_str()); }
                if (CampaignId.length() > 0) { writer.String("CampaignId"); writer.String(CampaignId.c_str()); }
                writer.String("AttributedAt"); writeDatetime(AttributedAt, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();
                const Value::ConstMemberIterator CampaignId_member = obj.FindMember("CampaignId");
                if (CampaignId_member != obj.MemberEnd() && !CampaignId_member->value.IsNull()) CampaignId = CampaignId_member->value.GetString();
                const Value::ConstMemberIterator AttributedAt_member = obj.FindMember("AttributedAt");
                if (AttributedAt_member != obj.MemberEnd() && !AttributedAt_member->value.IsNull()) AttributedAt = readDatetime(AttributedAt_member->value);

                return true;
            }
        };

        struct AddCharacterVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String VirtualCurrency;
            Int32 Amount;

            AddCharacterVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                VirtualCurrency(),
                Amount(0)
            {}

            AddCharacterVirtualCurrencyRequest(const AddCharacterVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            AddCharacterVirtualCurrencyRequest(const rapidjson::Value& obj) : AddCharacterVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddCharacterVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
                writer.String("Amount"); writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct AddFriendRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String FriendPlayFabId;
            Aws::String FriendUsername;
            Aws::String FriendEmail;
            Aws::String FriendTitleDisplayName;

            AddFriendRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                FriendPlayFabId(),
                FriendUsername(),
                FriendEmail(),
                FriendTitleDisplayName()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendUsername(src.FriendUsername),
                FriendEmail(src.FriendEmail),
                FriendTitleDisplayName(src.FriendTitleDisplayName)
            {}

            AddFriendRequest(const rapidjson::Value& obj) : AddFriendRequest()
            {
                readFromValue(obj);
            }

            ~AddFriendRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (FriendPlayFabId.length() > 0) { writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str()); }
                if (FriendUsername.length() > 0) { writer.String("FriendUsername"); writer.String(FriendUsername.c_str()); }
                if (FriendEmail.length() > 0) { writer.String("FriendEmail"); writer.String(FriendEmail.c_str()); }
                if (FriendTitleDisplayName.length() > 0) { writer.String("FriendTitleDisplayName"); writer.String(FriendTitleDisplayName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator FriendUsername_member = obj.FindMember("FriendUsername");
                if (FriendUsername_member != obj.MemberEnd() && !FriendUsername_member->value.IsNull()) FriendUsername = FriendUsername_member->value.GetString();
                const Value::ConstMemberIterator FriendEmail_member = obj.FindMember("FriendEmail");
                if (FriendEmail_member != obj.MemberEnd() && !FriendEmail_member->value.IsNull()) FriendEmail = FriendEmail_member->value.GetString();
                const Value::ConstMemberIterator FriendTitleDisplayName_member = obj.FindMember("FriendTitleDisplayName");
                if (FriendTitleDisplayName_member != obj.MemberEnd() && !FriendTitleDisplayName_member->value.IsNull()) FriendTitleDisplayName = FriendTitleDisplayName_member->value.GetString();

                return true;
            }
        };

        struct AddPlayerTagRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String TagName;

            AddPlayerTagRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                TagName()
            {}

            AddPlayerTagRequest(const AddPlayerTagRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            AddPlayerTagRequest(const rapidjson::Value& obj) : AddPlayerTagRequest()
            {
                readFromValue(obj);
            }

            ~AddPlayerTagRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("TagName"); writer.String(TagName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator TagName_member = obj.FindMember("TagName");
                if (TagName_member != obj.MemberEnd() && !TagName_member->value.IsNull()) TagName = TagName_member->value.GetString();

                return true;
            }
        };

        struct AddPlayerTagResult : public PlayFabBaseModel
        {

            AddPlayerTagResult() :
                PlayFabBaseModel()
            {}

            AddPlayerTagResult(const AddPlayerTagResult& src) :
                PlayFabBaseModel()
            {}

            AddPlayerTagResult(const rapidjson::Value& obj) : AddPlayerTagResult()
            {
                readFromValue(obj);
            }

            ~AddPlayerTagResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AddSharedGroupMembersRequest : public PlayFabBaseModel
        {
            Aws::String SharedGroupId;
            std::list<Aws::String> PlayFabIds;

            AddSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                PlayFabIds()
            {}

            AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                PlayFabIds(src.PlayFabIds)
            {}

            AddSharedGroupMembersRequest(const rapidjson::Value& obj) : AddSharedGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~AddSharedGroupMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
                writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct AddSharedGroupMembersResult : public PlayFabBaseModel
        {

            AddSharedGroupMembersResult() :
                PlayFabBaseModel()
            {}

            AddSharedGroupMembersResult(const AddSharedGroupMembersResult& src) :
                PlayFabBaseModel()
            {}

            AddSharedGroupMembersResult(const rapidjson::Value& obj) : AddSharedGroupMembersResult()
            {
                readFromValue(obj);
            }

            ~AddSharedGroupMembersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String VirtualCurrency;
            Int32 Amount;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                Amount(0)
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            AddUserVirtualCurrencyRequest(const rapidjson::Value& obj) : AddUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddUserVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
                writer.String("Amount"); writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct AuthenticateSessionTicketRequest : public PlayFabBaseModel
        {
            Aws::String SessionTicket;

            AuthenticateSessionTicketRequest() :
                PlayFabBaseModel(),
                SessionTicket()
            {}

            AuthenticateSessionTicketRequest(const AuthenticateSessionTicketRequest& src) :
                PlayFabBaseModel(),
                SessionTicket(src.SessionTicket)
            {}

            AuthenticateSessionTicketRequest(const rapidjson::Value& obj) : AuthenticateSessionTicketRequest()
            {
                readFromValue(obj);
            }

            ~AuthenticateSessionTicketRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SessionTicket"); writer.String(SessionTicket.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SessionTicket_member = obj.FindMember("SessionTicket");
                if (SessionTicket_member != obj.MemberEnd() && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();

                return true;
            }
        };

        enum UserOrigination
        {
            UserOriginationOrganic,
            UserOriginationSteam,
            UserOriginationGoogle,
            UserOriginationAmazon,
            UserOriginationFacebook,
            UserOriginationKongregate,
            UserOriginationGamersFirst,
            UserOriginationUnknown,
            UserOriginationIOS,
            UserOriginationLoadTest,
            UserOriginationAndroid,
            UserOriginationPSN,
            UserOriginationGameCenter,
            UserOriginationCustomId,
            UserOriginationXboxLive,
            UserOriginationParse,
            UserOriginationTwitch,
            UserOriginationWindowsHello
        };

        inline void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case UserOriginationOrganic: writer.String("Organic"); break;
            case UserOriginationSteam: writer.String("Steam"); break;
            case UserOriginationGoogle: writer.String("Google"); break;
            case UserOriginationAmazon: writer.String("Amazon"); break;
            case UserOriginationFacebook: writer.String("Facebook"); break;
            case UserOriginationKongregate: writer.String("Kongregate"); break;
            case UserOriginationGamersFirst: writer.String("GamersFirst"); break;
            case UserOriginationUnknown: writer.String("Unknown"); break;
            case UserOriginationIOS: writer.String("IOS"); break;
            case UserOriginationLoadTest: writer.String("LoadTest"); break;
            case UserOriginationAndroid: writer.String("Android"); break;
            case UserOriginationPSN: writer.String("PSN"); break;
            case UserOriginationGameCenter: writer.String("GameCenter"); break;
            case UserOriginationCustomId: writer.String("CustomId"); break;
            case UserOriginationXboxLive: writer.String("XboxLive"); break;
            case UserOriginationParse: writer.String("Parse"); break;
            case UserOriginationTwitch: writer.String("Twitch"); break;
            case UserOriginationWindowsHello: writer.String("WindowsHello"); break;

            }
        }

        inline UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, UserOrigination> _UserOriginationMap;
            if (_UserOriginationMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _UserOriginationMap["Organic"] = UserOriginationOrganic;
                _UserOriginationMap["Steam"] = UserOriginationSteam;
                _UserOriginationMap["Google"] = UserOriginationGoogle;
                _UserOriginationMap["Amazon"] = UserOriginationAmazon;
                _UserOriginationMap["Facebook"] = UserOriginationFacebook;
                _UserOriginationMap["Kongregate"] = UserOriginationKongregate;
                _UserOriginationMap["GamersFirst"] = UserOriginationGamersFirst;
                _UserOriginationMap["Unknown"] = UserOriginationUnknown;
                _UserOriginationMap["IOS"] = UserOriginationIOS;
                _UserOriginationMap["LoadTest"] = UserOriginationLoadTest;
                _UserOriginationMap["Android"] = UserOriginationAndroid;
                _UserOriginationMap["PSN"] = UserOriginationPSN;
                _UserOriginationMap["GameCenter"] = UserOriginationGameCenter;
                _UserOriginationMap["CustomId"] = UserOriginationCustomId;
                _UserOriginationMap["XboxLive"] = UserOriginationXboxLive;
                _UserOriginationMap["Parse"] = UserOriginationParse;
                _UserOriginationMap["Twitch"] = UserOriginationTwitch;
                _UserOriginationMap["WindowsHello"] = UserOriginationWindowsHello;

            }

            auto output = _UserOriginationMap.find(obj.GetString());
            if (output != _UserOriginationMap.end())
                return output->second;

            return UserOriginationOrganic; // Basically critical fail
        }

        struct UserTitleInfo : public PlayFabBaseModel
        {
            Aws::String DisplayName;
            Boxed<UserOrigination> Origination;
            time_t Created;
            OptionalTime LastLogin;
            OptionalTime FirstLogin;
            OptionalBool isBanned;
            Aws::String AvatarUrl;

            UserTitleInfo() :
                PlayFabBaseModel(),
                DisplayName(),
                Origination(),
                Created(0),
                LastLogin(),
                FirstLogin(),
                isBanned(),
                AvatarUrl()
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Origination(src.Origination),
                Created(src.Created),
                LastLogin(src.LastLogin),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned),
                AvatarUrl(src.AvatarUrl)
            {}

            UserTitleInfo(const rapidjson::Value& obj) : UserTitleInfo()
            {
                readFromValue(obj);
            }

            ~UserTitleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (Origination.notNull()) { writer.String("Origination"); writeUserOriginationEnumJSON(Origination, writer); }
                writer.String("Created"); writeDatetime(Created, writer);
                if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
                if (FirstLogin.notNull()) { writer.String("FirstLogin"); writeDatetime(FirstLogin, writer); }
                if (isBanned.notNull()) { writer.String("isBanned"); writer.Bool(isBanned); }
                if (AvatarUrl.length() > 0) { writer.String("AvatarUrl"); writer.String(AvatarUrl.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readUserOriginationFromValue(Origination_member->value);
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator FirstLogin_member = obj.FindMember("FirstLogin");
                if (FirstLogin_member != obj.MemberEnd() && !FirstLogin_member->value.IsNull()) FirstLogin = readDatetime(FirstLogin_member->value);
                const Value::ConstMemberIterator isBanned_member = obj.FindMember("isBanned");
                if (isBanned_member != obj.MemberEnd() && !isBanned_member->value.IsNull()) isBanned = isBanned_member->value.GetBool();
                const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
                if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();

                return true;
            }
        };

        struct UserPrivateAccountInfo : public PlayFabBaseModel
        {
            Aws::String Email;

            UserPrivateAccountInfo() :
                PlayFabBaseModel(),
                Email()
            {}

            UserPrivateAccountInfo(const UserPrivateAccountInfo& src) :
                PlayFabBaseModel(),
                Email(src.Email)
            {}

            UserPrivateAccountInfo(const rapidjson::Value& obj) : UserPrivateAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserPrivateAccountInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct UserFacebookInfo : public PlayFabBaseModel
        {
            Aws::String FacebookId;
            Aws::String FullName;

            UserFacebookInfo() :
                PlayFabBaseModel(),
                FacebookId(),
                FullName()
            {}

            UserFacebookInfo(const UserFacebookInfo& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                FullName(src.FullName)
            {}

            UserFacebookInfo(const rapidjson::Value& obj) : UserFacebookInfo()
            {
                readFromValue(obj);
            }

            ~UserFacebookInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FacebookId.length() > 0) { writer.String("FacebookId"); writer.String(FacebookId.c_str()); }
                if (FullName.length() > 0) { writer.String("FullName"); writer.String(FullName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
                if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
                const Value::ConstMemberIterator FullName_member = obj.FindMember("FullName");
                if (FullName_member != obj.MemberEnd() && !FullName_member->value.IsNull()) FullName = FullName_member->value.GetString();

                return true;
            }
        };

        enum Currency
        {
            CurrencyAED,
            CurrencyAFN,
            CurrencyALL,
            CurrencyAMD,
            CurrencyANG,
            CurrencyAOA,
            CurrencyARS,
            CurrencyAUD,
            CurrencyAWG,
            CurrencyAZN,
            CurrencyBAM,
            CurrencyBBD,
            CurrencyBDT,
            CurrencyBGN,
            CurrencyBHD,
            CurrencyBIF,
            CurrencyBMD,
            CurrencyBND,
            CurrencyBOB,
            CurrencyBRL,
            CurrencyBSD,
            CurrencyBTN,
            CurrencyBWP,
            CurrencyBYR,
            CurrencyBZD,
            CurrencyCAD,
            CurrencyCDF,
            CurrencyCHF,
            CurrencyCLP,
            CurrencyCNY,
            CurrencyCOP,
            CurrencyCRC,
            CurrencyCUC,
            CurrencyCUP,
            CurrencyCVE,
            CurrencyCZK,
            CurrencyDJF,
            CurrencyDKK,
            CurrencyDOP,
            CurrencyDZD,
            CurrencyEGP,
            CurrencyERN,
            CurrencyETB,
            CurrencyEUR,
            CurrencyFJD,
            CurrencyFKP,
            CurrencyGBP,
            CurrencyGEL,
            CurrencyGGP,
            CurrencyGHS,
            CurrencyGIP,
            CurrencyGMD,
            CurrencyGNF,
            CurrencyGTQ,
            CurrencyGYD,
            CurrencyHKD,
            CurrencyHNL,
            CurrencyHRK,
            CurrencyHTG,
            CurrencyHUF,
            CurrencyIDR,
            CurrencyILS,
            CurrencyIMP,
            CurrencyINR,
            CurrencyIQD,
            CurrencyIRR,
            CurrencyISK,
            CurrencyJEP,
            CurrencyJMD,
            CurrencyJOD,
            CurrencyJPY,
            CurrencyKES,
            CurrencyKGS,
            CurrencyKHR,
            CurrencyKMF,
            CurrencyKPW,
            CurrencyKRW,
            CurrencyKWD,
            CurrencyKYD,
            CurrencyKZT,
            CurrencyLAK,
            CurrencyLBP,
            CurrencyLKR,
            CurrencyLRD,
            CurrencyLSL,
            CurrencyLYD,
            CurrencyMAD,
            CurrencyMDL,
            CurrencyMGA,
            CurrencyMKD,
            CurrencyMMK,
            CurrencyMNT,
            CurrencyMOP,
            CurrencyMRO,
            CurrencyMUR,
            CurrencyMVR,
            CurrencyMWK,
            CurrencyMXN,
            CurrencyMYR,
            CurrencyMZN,
            CurrencyNAD,
            CurrencyNGN,
            CurrencyNIO,
            CurrencyNOK,
            CurrencyNPR,
            CurrencyNZD,
            CurrencyOMR,
            CurrencyPAB,
            CurrencyPEN,
            CurrencyPGK,
            CurrencyPHP,
            CurrencyPKR,
            CurrencyPLN,
            CurrencyPYG,
            CurrencyQAR,
            CurrencyRON,
            CurrencyRSD,
            CurrencyRUB,
            CurrencyRWF,
            CurrencySAR,
            CurrencySBD,
            CurrencySCR,
            CurrencySDG,
            CurrencySEK,
            CurrencySGD,
            CurrencySHP,
            CurrencySLL,
            CurrencySOS,
            CurrencySPL,
            CurrencySRD,
            CurrencySTD,
            CurrencySVC,
            CurrencySYP,
            CurrencySZL,
            CurrencyTHB,
            CurrencyTJS,
            CurrencyTMT,
            CurrencyTND,
            CurrencyTOP,
            CurrencyTRY,
            CurrencyTTD,
            CurrencyTVD,
            CurrencyTWD,
            CurrencyTZS,
            CurrencyUAH,
            CurrencyUGX,
            CurrencyUSD,
            CurrencyUYU,
            CurrencyUZS,
            CurrencyVEF,
            CurrencyVND,
            CurrencyVUV,
            CurrencyWST,
            CurrencyXAF,
            CurrencyXCD,
            CurrencyXDR,
            CurrencyXOF,
            CurrencyXPF,
            CurrencyYER,
            CurrencyZAR,
            CurrencyZMW,
            CurrencyZWD
        };

        inline void writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CurrencyAED: writer.String("AED"); break;
            case CurrencyAFN: writer.String("AFN"); break;
            case CurrencyALL: writer.String("ALL"); break;
            case CurrencyAMD: writer.String("AMD"); break;
            case CurrencyANG: writer.String("ANG"); break;
            case CurrencyAOA: writer.String("AOA"); break;
            case CurrencyARS: writer.String("ARS"); break;
            case CurrencyAUD: writer.String("AUD"); break;
            case CurrencyAWG: writer.String("AWG"); break;
            case CurrencyAZN: writer.String("AZN"); break;
            case CurrencyBAM: writer.String("BAM"); break;
            case CurrencyBBD: writer.String("BBD"); break;
            case CurrencyBDT: writer.String("BDT"); break;
            case CurrencyBGN: writer.String("BGN"); break;
            case CurrencyBHD: writer.String("BHD"); break;
            case CurrencyBIF: writer.String("BIF"); break;
            case CurrencyBMD: writer.String("BMD"); break;
            case CurrencyBND: writer.String("BND"); break;
            case CurrencyBOB: writer.String("BOB"); break;
            case CurrencyBRL: writer.String("BRL"); break;
            case CurrencyBSD: writer.String("BSD"); break;
            case CurrencyBTN: writer.String("BTN"); break;
            case CurrencyBWP: writer.String("BWP"); break;
            case CurrencyBYR: writer.String("BYR"); break;
            case CurrencyBZD: writer.String("BZD"); break;
            case CurrencyCAD: writer.String("CAD"); break;
            case CurrencyCDF: writer.String("CDF"); break;
            case CurrencyCHF: writer.String("CHF"); break;
            case CurrencyCLP: writer.String("CLP"); break;
            case CurrencyCNY: writer.String("CNY"); break;
            case CurrencyCOP: writer.String("COP"); break;
            case CurrencyCRC: writer.String("CRC"); break;
            case CurrencyCUC: writer.String("CUC"); break;
            case CurrencyCUP: writer.String("CUP"); break;
            case CurrencyCVE: writer.String("CVE"); break;
            case CurrencyCZK: writer.String("CZK"); break;
            case CurrencyDJF: writer.String("DJF"); break;
            case CurrencyDKK: writer.String("DKK"); break;
            case CurrencyDOP: writer.String("DOP"); break;
            case CurrencyDZD: writer.String("DZD"); break;
            case CurrencyEGP: writer.String("EGP"); break;
            case CurrencyERN: writer.String("ERN"); break;
            case CurrencyETB: writer.String("ETB"); break;
            case CurrencyEUR: writer.String("EUR"); break;
            case CurrencyFJD: writer.String("FJD"); break;
            case CurrencyFKP: writer.String("FKP"); break;
            case CurrencyGBP: writer.String("GBP"); break;
            case CurrencyGEL: writer.String("GEL"); break;
            case CurrencyGGP: writer.String("GGP"); break;
            case CurrencyGHS: writer.String("GHS"); break;
            case CurrencyGIP: writer.String("GIP"); break;
            case CurrencyGMD: writer.String("GMD"); break;
            case CurrencyGNF: writer.String("GNF"); break;
            case CurrencyGTQ: writer.String("GTQ"); break;
            case CurrencyGYD: writer.String("GYD"); break;
            case CurrencyHKD: writer.String("HKD"); break;
            case CurrencyHNL: writer.String("HNL"); break;
            case CurrencyHRK: writer.String("HRK"); break;
            case CurrencyHTG: writer.String("HTG"); break;
            case CurrencyHUF: writer.String("HUF"); break;
            case CurrencyIDR: writer.String("IDR"); break;
            case CurrencyILS: writer.String("ILS"); break;
            case CurrencyIMP: writer.String("IMP"); break;
            case CurrencyINR: writer.String("INR"); break;
            case CurrencyIQD: writer.String("IQD"); break;
            case CurrencyIRR: writer.String("IRR"); break;
            case CurrencyISK: writer.String("ISK"); break;
            case CurrencyJEP: writer.String("JEP"); break;
            case CurrencyJMD: writer.String("JMD"); break;
            case CurrencyJOD: writer.String("JOD"); break;
            case CurrencyJPY: writer.String("JPY"); break;
            case CurrencyKES: writer.String("KES"); break;
            case CurrencyKGS: writer.String("KGS"); break;
            case CurrencyKHR: writer.String("KHR"); break;
            case CurrencyKMF: writer.String("KMF"); break;
            case CurrencyKPW: writer.String("KPW"); break;
            case CurrencyKRW: writer.String("KRW"); break;
            case CurrencyKWD: writer.String("KWD"); break;
            case CurrencyKYD: writer.String("KYD"); break;
            case CurrencyKZT: writer.String("KZT"); break;
            case CurrencyLAK: writer.String("LAK"); break;
            case CurrencyLBP: writer.String("LBP"); break;
            case CurrencyLKR: writer.String("LKR"); break;
            case CurrencyLRD: writer.String("LRD"); break;
            case CurrencyLSL: writer.String("LSL"); break;
            case CurrencyLYD: writer.String("LYD"); break;
            case CurrencyMAD: writer.String("MAD"); break;
            case CurrencyMDL: writer.String("MDL"); break;
            case CurrencyMGA: writer.String("MGA"); break;
            case CurrencyMKD: writer.String("MKD"); break;
            case CurrencyMMK: writer.String("MMK"); break;
            case CurrencyMNT: writer.String("MNT"); break;
            case CurrencyMOP: writer.String("MOP"); break;
            case CurrencyMRO: writer.String("MRO"); break;
            case CurrencyMUR: writer.String("MUR"); break;
            case CurrencyMVR: writer.String("MVR"); break;
            case CurrencyMWK: writer.String("MWK"); break;
            case CurrencyMXN: writer.String("MXN"); break;
            case CurrencyMYR: writer.String("MYR"); break;
            case CurrencyMZN: writer.String("MZN"); break;
            case CurrencyNAD: writer.String("NAD"); break;
            case CurrencyNGN: writer.String("NGN"); break;
            case CurrencyNIO: writer.String("NIO"); break;
            case CurrencyNOK: writer.String("NOK"); break;
            case CurrencyNPR: writer.String("NPR"); break;
            case CurrencyNZD: writer.String("NZD"); break;
            case CurrencyOMR: writer.String("OMR"); break;
            case CurrencyPAB: writer.String("PAB"); break;
            case CurrencyPEN: writer.String("PEN"); break;
            case CurrencyPGK: writer.String("PGK"); break;
            case CurrencyPHP: writer.String("PHP"); break;
            case CurrencyPKR: writer.String("PKR"); break;
            case CurrencyPLN: writer.String("PLN"); break;
            case CurrencyPYG: writer.String("PYG"); break;
            case CurrencyQAR: writer.String("QAR"); break;
            case CurrencyRON: writer.String("RON"); break;
            case CurrencyRSD: writer.String("RSD"); break;
            case CurrencyRUB: writer.String("RUB"); break;
            case CurrencyRWF: writer.String("RWF"); break;
            case CurrencySAR: writer.String("SAR"); break;
            case CurrencySBD: writer.String("SBD"); break;
            case CurrencySCR: writer.String("SCR"); break;
            case CurrencySDG: writer.String("SDG"); break;
            case CurrencySEK: writer.String("SEK"); break;
            case CurrencySGD: writer.String("SGD"); break;
            case CurrencySHP: writer.String("SHP"); break;
            case CurrencySLL: writer.String("SLL"); break;
            case CurrencySOS: writer.String("SOS"); break;
            case CurrencySPL: writer.String("SPL"); break;
            case CurrencySRD: writer.String("SRD"); break;
            case CurrencySTD: writer.String("STD"); break;
            case CurrencySVC: writer.String("SVC"); break;
            case CurrencySYP: writer.String("SYP"); break;
            case CurrencySZL: writer.String("SZL"); break;
            case CurrencyTHB: writer.String("THB"); break;
            case CurrencyTJS: writer.String("TJS"); break;
            case CurrencyTMT: writer.String("TMT"); break;
            case CurrencyTND: writer.String("TND"); break;
            case CurrencyTOP: writer.String("TOP"); break;
            case CurrencyTRY: writer.String("TRY"); break;
            case CurrencyTTD: writer.String("TTD"); break;
            case CurrencyTVD: writer.String("TVD"); break;
            case CurrencyTWD: writer.String("TWD"); break;
            case CurrencyTZS: writer.String("TZS"); break;
            case CurrencyUAH: writer.String("UAH"); break;
            case CurrencyUGX: writer.String("UGX"); break;
            case CurrencyUSD: writer.String("USD"); break;
            case CurrencyUYU: writer.String("UYU"); break;
            case CurrencyUZS: writer.String("UZS"); break;
            case CurrencyVEF: writer.String("VEF"); break;
            case CurrencyVND: writer.String("VND"); break;
            case CurrencyVUV: writer.String("VUV"); break;
            case CurrencyWST: writer.String("WST"); break;
            case CurrencyXAF: writer.String("XAF"); break;
            case CurrencyXCD: writer.String("XCD"); break;
            case CurrencyXDR: writer.String("XDR"); break;
            case CurrencyXOF: writer.String("XOF"); break;
            case CurrencyXPF: writer.String("XPF"); break;
            case CurrencyYER: writer.String("YER"); break;
            case CurrencyZAR: writer.String("ZAR"); break;
            case CurrencyZMW: writer.String("ZMW"); break;
            case CurrencyZWD: writer.String("ZWD"); break;

            }
        }

        inline Currency readCurrencyFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, Currency> _CurrencyMap;
            if (_CurrencyMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CurrencyMap["AED"] = CurrencyAED;
                _CurrencyMap["AFN"] = CurrencyAFN;
                _CurrencyMap["ALL"] = CurrencyALL;
                _CurrencyMap["AMD"] = CurrencyAMD;
                _CurrencyMap["ANG"] = CurrencyANG;
                _CurrencyMap["AOA"] = CurrencyAOA;
                _CurrencyMap["ARS"] = CurrencyARS;
                _CurrencyMap["AUD"] = CurrencyAUD;
                _CurrencyMap["AWG"] = CurrencyAWG;
                _CurrencyMap["AZN"] = CurrencyAZN;
                _CurrencyMap["BAM"] = CurrencyBAM;
                _CurrencyMap["BBD"] = CurrencyBBD;
                _CurrencyMap["BDT"] = CurrencyBDT;
                _CurrencyMap["BGN"] = CurrencyBGN;
                _CurrencyMap["BHD"] = CurrencyBHD;
                _CurrencyMap["BIF"] = CurrencyBIF;
                _CurrencyMap["BMD"] = CurrencyBMD;
                _CurrencyMap["BND"] = CurrencyBND;
                _CurrencyMap["BOB"] = CurrencyBOB;
                _CurrencyMap["BRL"] = CurrencyBRL;
                _CurrencyMap["BSD"] = CurrencyBSD;
                _CurrencyMap["BTN"] = CurrencyBTN;
                _CurrencyMap["BWP"] = CurrencyBWP;
                _CurrencyMap["BYR"] = CurrencyBYR;
                _CurrencyMap["BZD"] = CurrencyBZD;
                _CurrencyMap["CAD"] = CurrencyCAD;
                _CurrencyMap["CDF"] = CurrencyCDF;
                _CurrencyMap["CHF"] = CurrencyCHF;
                _CurrencyMap["CLP"] = CurrencyCLP;
                _CurrencyMap["CNY"] = CurrencyCNY;
                _CurrencyMap["COP"] = CurrencyCOP;
                _CurrencyMap["CRC"] = CurrencyCRC;
                _CurrencyMap["CUC"] = CurrencyCUC;
                _CurrencyMap["CUP"] = CurrencyCUP;
                _CurrencyMap["CVE"] = CurrencyCVE;
                _CurrencyMap["CZK"] = CurrencyCZK;
                _CurrencyMap["DJF"] = CurrencyDJF;
                _CurrencyMap["DKK"] = CurrencyDKK;
                _CurrencyMap["DOP"] = CurrencyDOP;
                _CurrencyMap["DZD"] = CurrencyDZD;
                _CurrencyMap["EGP"] = CurrencyEGP;
                _CurrencyMap["ERN"] = CurrencyERN;
                _CurrencyMap["ETB"] = CurrencyETB;
                _CurrencyMap["EUR"] = CurrencyEUR;
                _CurrencyMap["FJD"] = CurrencyFJD;
                _CurrencyMap["FKP"] = CurrencyFKP;
                _CurrencyMap["GBP"] = CurrencyGBP;
                _CurrencyMap["GEL"] = CurrencyGEL;
                _CurrencyMap["GGP"] = CurrencyGGP;
                _CurrencyMap["GHS"] = CurrencyGHS;
                _CurrencyMap["GIP"] = CurrencyGIP;
                _CurrencyMap["GMD"] = CurrencyGMD;
                _CurrencyMap["GNF"] = CurrencyGNF;
                _CurrencyMap["GTQ"] = CurrencyGTQ;
                _CurrencyMap["GYD"] = CurrencyGYD;
                _CurrencyMap["HKD"] = CurrencyHKD;
                _CurrencyMap["HNL"] = CurrencyHNL;
                _CurrencyMap["HRK"] = CurrencyHRK;
                _CurrencyMap["HTG"] = CurrencyHTG;
                _CurrencyMap["HUF"] = CurrencyHUF;
                _CurrencyMap["IDR"] = CurrencyIDR;
                _CurrencyMap["ILS"] = CurrencyILS;
                _CurrencyMap["IMP"] = CurrencyIMP;
                _CurrencyMap["INR"] = CurrencyINR;
                _CurrencyMap["IQD"] = CurrencyIQD;
                _CurrencyMap["IRR"] = CurrencyIRR;
                _CurrencyMap["ISK"] = CurrencyISK;
                _CurrencyMap["JEP"] = CurrencyJEP;
                _CurrencyMap["JMD"] = CurrencyJMD;
                _CurrencyMap["JOD"] = CurrencyJOD;
                _CurrencyMap["JPY"] = CurrencyJPY;
                _CurrencyMap["KES"] = CurrencyKES;
                _CurrencyMap["KGS"] = CurrencyKGS;
                _CurrencyMap["KHR"] = CurrencyKHR;
                _CurrencyMap["KMF"] = CurrencyKMF;
                _CurrencyMap["KPW"] = CurrencyKPW;
                _CurrencyMap["KRW"] = CurrencyKRW;
                _CurrencyMap["KWD"] = CurrencyKWD;
                _CurrencyMap["KYD"] = CurrencyKYD;
                _CurrencyMap["KZT"] = CurrencyKZT;
                _CurrencyMap["LAK"] = CurrencyLAK;
                _CurrencyMap["LBP"] = CurrencyLBP;
                _CurrencyMap["LKR"] = CurrencyLKR;
                _CurrencyMap["LRD"] = CurrencyLRD;
                _CurrencyMap["LSL"] = CurrencyLSL;
                _CurrencyMap["LYD"] = CurrencyLYD;
                _CurrencyMap["MAD"] = CurrencyMAD;
                _CurrencyMap["MDL"] = CurrencyMDL;
                _CurrencyMap["MGA"] = CurrencyMGA;
                _CurrencyMap["MKD"] = CurrencyMKD;
                _CurrencyMap["MMK"] = CurrencyMMK;
                _CurrencyMap["MNT"] = CurrencyMNT;
                _CurrencyMap["MOP"] = CurrencyMOP;
                _CurrencyMap["MRO"] = CurrencyMRO;
                _CurrencyMap["MUR"] = CurrencyMUR;
                _CurrencyMap["MVR"] = CurrencyMVR;
                _CurrencyMap["MWK"] = CurrencyMWK;
                _CurrencyMap["MXN"] = CurrencyMXN;
                _CurrencyMap["MYR"] = CurrencyMYR;
                _CurrencyMap["MZN"] = CurrencyMZN;
                _CurrencyMap["NAD"] = CurrencyNAD;
                _CurrencyMap["NGN"] = CurrencyNGN;
                _CurrencyMap["NIO"] = CurrencyNIO;
                _CurrencyMap["NOK"] = CurrencyNOK;
                _CurrencyMap["NPR"] = CurrencyNPR;
                _CurrencyMap["NZD"] = CurrencyNZD;
                _CurrencyMap["OMR"] = CurrencyOMR;
                _CurrencyMap["PAB"] = CurrencyPAB;
                _CurrencyMap["PEN"] = CurrencyPEN;
                _CurrencyMap["PGK"] = CurrencyPGK;
                _CurrencyMap["PHP"] = CurrencyPHP;
                _CurrencyMap["PKR"] = CurrencyPKR;
                _CurrencyMap["PLN"] = CurrencyPLN;
                _CurrencyMap["PYG"] = CurrencyPYG;
                _CurrencyMap["QAR"] = CurrencyQAR;
                _CurrencyMap["RON"] = CurrencyRON;
                _CurrencyMap["RSD"] = CurrencyRSD;
                _CurrencyMap["RUB"] = CurrencyRUB;
                _CurrencyMap["RWF"] = CurrencyRWF;
                _CurrencyMap["SAR"] = CurrencySAR;
                _CurrencyMap["SBD"] = CurrencySBD;
                _CurrencyMap["SCR"] = CurrencySCR;
                _CurrencyMap["SDG"] = CurrencySDG;
                _CurrencyMap["SEK"] = CurrencySEK;
                _CurrencyMap["SGD"] = CurrencySGD;
                _CurrencyMap["SHP"] = CurrencySHP;
                _CurrencyMap["SLL"] = CurrencySLL;
                _CurrencyMap["SOS"] = CurrencySOS;
                _CurrencyMap["SPL"] = CurrencySPL;
                _CurrencyMap["SRD"] = CurrencySRD;
                _CurrencyMap["STD"] = CurrencySTD;
                _CurrencyMap["SVC"] = CurrencySVC;
                _CurrencyMap["SYP"] = CurrencySYP;
                _CurrencyMap["SZL"] = CurrencySZL;
                _CurrencyMap["THB"] = CurrencyTHB;
                _CurrencyMap["TJS"] = CurrencyTJS;
                _CurrencyMap["TMT"] = CurrencyTMT;
                _CurrencyMap["TND"] = CurrencyTND;
                _CurrencyMap["TOP"] = CurrencyTOP;
                _CurrencyMap["TRY"] = CurrencyTRY;
                _CurrencyMap["TTD"] = CurrencyTTD;
                _CurrencyMap["TVD"] = CurrencyTVD;
                _CurrencyMap["TWD"] = CurrencyTWD;
                _CurrencyMap["TZS"] = CurrencyTZS;
                _CurrencyMap["UAH"] = CurrencyUAH;
                _CurrencyMap["UGX"] = CurrencyUGX;
                _CurrencyMap["USD"] = CurrencyUSD;
                _CurrencyMap["UYU"] = CurrencyUYU;
                _CurrencyMap["UZS"] = CurrencyUZS;
                _CurrencyMap["VEF"] = CurrencyVEF;
                _CurrencyMap["VND"] = CurrencyVND;
                _CurrencyMap["VUV"] = CurrencyVUV;
                _CurrencyMap["WST"] = CurrencyWST;
                _CurrencyMap["XAF"] = CurrencyXAF;
                _CurrencyMap["XCD"] = CurrencyXCD;
                _CurrencyMap["XDR"] = CurrencyXDR;
                _CurrencyMap["XOF"] = CurrencyXOF;
                _CurrencyMap["XPF"] = CurrencyXPF;
                _CurrencyMap["YER"] = CurrencyYER;
                _CurrencyMap["ZAR"] = CurrencyZAR;
                _CurrencyMap["ZMW"] = CurrencyZMW;
                _CurrencyMap["ZWD"] = CurrencyZWD;

            }

            auto output = _CurrencyMap.find(obj.GetString());
            if (output != _CurrencyMap.end())
                return output->second;

            return CurrencyAED; // Basically critical fail
        }

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        inline void writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TitleActivationStatusNone: writer.String("None"); break;
            case TitleActivationStatusActivatedTitleKey: writer.String("ActivatedTitleKey"); break;
            case TitleActivationStatusPendingSteam: writer.String("PendingSteam"); break;
            case TitleActivationStatusActivatedSteam: writer.String("ActivatedSteam"); break;
            case TitleActivationStatusRevokedSteam: writer.String("RevokedSteam"); break;

            }
        }

        inline TitleActivationStatus readTitleActivationStatusFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, TitleActivationStatus> _TitleActivationStatusMap;
            if (_TitleActivationStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TitleActivationStatusMap["None"] = TitleActivationStatusNone;
                _TitleActivationStatusMap["ActivatedTitleKey"] = TitleActivationStatusActivatedTitleKey;
                _TitleActivationStatusMap["PendingSteam"] = TitleActivationStatusPendingSteam;
                _TitleActivationStatusMap["ActivatedSteam"] = TitleActivationStatusActivatedSteam;
                _TitleActivationStatusMap["RevokedSteam"] = TitleActivationStatusRevokedSteam;

            }

            auto output = _TitleActivationStatusMap.find(obj.GetString());
            if (output != _TitleActivationStatusMap.end())
                return output->second;

            return TitleActivationStatusNone; // Basically critical fail
        }

        struct UserSteamInfo : public PlayFabBaseModel
        {
            Aws::String SteamId;
            Aws::String SteamCountry;
            Boxed<Currency> SteamCurrency;
            Boxed<TitleActivationStatus> SteamActivationStatus;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamId(),
                SteamCountry(),
                SteamCurrency(),
                SteamActivationStatus()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamId(src.SteamId),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamActivationStatus(src.SteamActivationStatus)
            {}

            UserSteamInfo(const rapidjson::Value& obj) : UserSteamInfo()
            {
                readFromValue(obj);
            }

            ~UserSteamInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
                if (SteamCountry.length() > 0) { writer.String("SteamCountry"); writer.String(SteamCountry.c_str()); }
                if (SteamCurrency.notNull()) { writer.String("SteamCurrency"); writeCurrencyEnumJSON(SteamCurrency, writer); }
                if (SteamActivationStatus.notNull()) { writer.String("SteamActivationStatus"); writeTitleActivationStatusEnumJSON(SteamActivationStatus, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
                if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();
                const Value::ConstMemberIterator SteamCountry_member = obj.FindMember("SteamCountry");
                if (SteamCountry_member != obj.MemberEnd() && !SteamCountry_member->value.IsNull()) SteamCountry = SteamCountry_member->value.GetString();
                const Value::ConstMemberIterator SteamCurrency_member = obj.FindMember("SteamCurrency");
                if (SteamCurrency_member != obj.MemberEnd() && !SteamCurrency_member->value.IsNull()) SteamCurrency = readCurrencyFromValue(SteamCurrency_member->value);
                const Value::ConstMemberIterator SteamActivationStatus_member = obj.FindMember("SteamActivationStatus");
                if (SteamActivationStatus_member != obj.MemberEnd() && !SteamActivationStatus_member->value.IsNull()) SteamActivationStatus = readTitleActivationStatusFromValue(SteamActivationStatus_member->value);

                return true;
            }
        };

        struct UserGameCenterInfo : public PlayFabBaseModel
        {
            Aws::String GameCenterId;

            UserGameCenterInfo() :
                PlayFabBaseModel(),
                GameCenterId()
            {}

            UserGameCenterInfo(const UserGameCenterInfo& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId)
            {}

            UserGameCenterInfo(const rapidjson::Value& obj) : UserGameCenterInfo()
            {
                readFromValue(obj);
            }

            ~UserGameCenterInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GameCenterId.length() > 0) { writer.String("GameCenterId"); writer.String(GameCenterId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
                if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();

                return true;
            }
        };

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
            Aws::String IosDeviceId;

            UserIosDeviceInfo() :
                PlayFabBaseModel(),
                IosDeviceId()
            {}

            UserIosDeviceInfo(const UserIosDeviceInfo& src) :
                PlayFabBaseModel(),
                IosDeviceId(src.IosDeviceId)
            {}

            UserIosDeviceInfo(const rapidjson::Value& obj) : UserIosDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserIosDeviceInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (IosDeviceId.length() > 0) { writer.String("IosDeviceId"); writer.String(IosDeviceId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IosDeviceId_member = obj.FindMember("IosDeviceId");
                if (IosDeviceId_member != obj.MemberEnd() && !IosDeviceId_member->value.IsNull()) IosDeviceId = IosDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UserAndroidDeviceInfo : public PlayFabBaseModel
        {
            Aws::String AndroidDeviceId;

            UserAndroidDeviceInfo() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UserAndroidDeviceInfo(const UserAndroidDeviceInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UserAndroidDeviceInfo(const rapidjson::Value& obj) : UserAndroidDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserAndroidDeviceInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AndroidDeviceId.length() > 0) { writer.String("AndroidDeviceId"); writer.String(AndroidDeviceId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UserKongregateInfo : public PlayFabBaseModel
        {
            Aws::String KongregateId;
            Aws::String KongregateName;

            UserKongregateInfo() :
                PlayFabBaseModel(),
                KongregateId(),
                KongregateName()
            {}

            UserKongregateInfo(const UserKongregateInfo& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                KongregateName(src.KongregateName)
            {}

            UserKongregateInfo(const rapidjson::Value& obj) : UserKongregateInfo()
            {
                readFromValue(obj);
            }

            ~UserKongregateInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (KongregateId.length() > 0) { writer.String("KongregateId"); writer.String(KongregateId.c_str()); }
                if (KongregateName.length() > 0) { writer.String("KongregateName"); writer.String(KongregateName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator KongregateName_member = obj.FindMember("KongregateName");
                if (KongregateName_member != obj.MemberEnd() && !KongregateName_member->value.IsNull()) KongregateName = KongregateName_member->value.GetString();

                return true;
            }
        };

        struct UserTwitchInfo : public PlayFabBaseModel
        {
            Aws::String TwitchId;
            Aws::String TwitchUserName;

            UserTwitchInfo() :
                PlayFabBaseModel(),
                TwitchId(),
                TwitchUserName()
            {}

            UserTwitchInfo(const UserTwitchInfo& src) :
                PlayFabBaseModel(),
                TwitchId(src.TwitchId),
                TwitchUserName(src.TwitchUserName)
            {}

            UserTwitchInfo(const rapidjson::Value& obj) : UserTwitchInfo()
            {
                readFromValue(obj);
            }

            ~UserTwitchInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TwitchId.length() > 0) { writer.String("TwitchId"); writer.String(TwitchId.c_str()); }
                if (TwitchUserName.length() > 0) { writer.String("TwitchUserName"); writer.String(TwitchUserName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TwitchId_member = obj.FindMember("TwitchId");
                if (TwitchId_member != obj.MemberEnd() && !TwitchId_member->value.IsNull()) TwitchId = TwitchId_member->value.GetString();
                const Value::ConstMemberIterator TwitchUserName_member = obj.FindMember("TwitchUserName");
                if (TwitchUserName_member != obj.MemberEnd() && !TwitchUserName_member->value.IsNull()) TwitchUserName = TwitchUserName_member->value.GetString();

                return true;
            }
        };

        struct UserPsnInfo : public PlayFabBaseModel
        {
            Aws::String PsnAccountId;
            Aws::String PsnOnlineId;

            UserPsnInfo() :
                PlayFabBaseModel(),
                PsnAccountId(),
                PsnOnlineId()
            {}

            UserPsnInfo(const UserPsnInfo& src) :
                PlayFabBaseModel(),
                PsnAccountId(src.PsnAccountId),
                PsnOnlineId(src.PsnOnlineId)
            {}

            UserPsnInfo(const rapidjson::Value& obj) : UserPsnInfo()
            {
                readFromValue(obj);
            }

            ~UserPsnInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PsnAccountId.length() > 0) { writer.String("PsnAccountId"); writer.String(PsnAccountId.c_str()); }
                if (PsnOnlineId.length() > 0) { writer.String("PsnOnlineId"); writer.String(PsnOnlineId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PsnAccountId_member = obj.FindMember("PsnAccountId");
                if (PsnAccountId_member != obj.MemberEnd() && !PsnAccountId_member->value.IsNull()) PsnAccountId = PsnAccountId_member->value.GetString();
                const Value::ConstMemberIterator PsnOnlineId_member = obj.FindMember("PsnOnlineId");
                if (PsnOnlineId_member != obj.MemberEnd() && !PsnOnlineId_member->value.IsNull()) PsnOnlineId = PsnOnlineId_member->value.GetString();

                return true;
            }
        };

        struct UserGoogleInfo : public PlayFabBaseModel
        {
            Aws::String GoogleId;
            Aws::String GoogleEmail;
            Aws::String GoogleLocale;
            Aws::String GoogleGender;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleId(),
                GoogleEmail(),
                GoogleLocale(),
                GoogleGender()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                GoogleEmail(src.GoogleEmail),
                GoogleLocale(src.GoogleLocale),
                GoogleGender(src.GoogleGender)
            {}

            UserGoogleInfo(const rapidjson::Value& obj) : UserGoogleInfo()
            {
                readFromValue(obj);
            }

            ~UserGoogleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GoogleId.length() > 0) { writer.String("GoogleId"); writer.String(GoogleId.c_str()); }
                if (GoogleEmail.length() > 0) { writer.String("GoogleEmail"); writer.String(GoogleEmail.c_str()); }
                if (GoogleLocale.length() > 0) { writer.String("GoogleLocale"); writer.String(GoogleLocale.c_str()); }
                if (GoogleGender.length() > 0) { writer.String("GoogleGender"); writer.String(GoogleGender.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GoogleId_member = obj.FindMember("GoogleId");
                if (GoogleId_member != obj.MemberEnd() && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
                const Value::ConstMemberIterator GoogleEmail_member = obj.FindMember("GoogleEmail");
                if (GoogleEmail_member != obj.MemberEnd() && !GoogleEmail_member->value.IsNull()) GoogleEmail = GoogleEmail_member->value.GetString();
                const Value::ConstMemberIterator GoogleLocale_member = obj.FindMember("GoogleLocale");
                if (GoogleLocale_member != obj.MemberEnd() && !GoogleLocale_member->value.IsNull()) GoogleLocale = GoogleLocale_member->value.GetString();
                const Value::ConstMemberIterator GoogleGender_member = obj.FindMember("GoogleGender");
                if (GoogleGender_member != obj.MemberEnd() && !GoogleGender_member->value.IsNull()) GoogleGender = GoogleGender_member->value.GetString();

                return true;
            }
        };

        struct UserXboxInfo : public PlayFabBaseModel
        {
            Aws::String XboxUserId;

            UserXboxInfo() :
                PlayFabBaseModel(),
                XboxUserId()
            {}

            UserXboxInfo(const UserXboxInfo& src) :
                PlayFabBaseModel(),
                XboxUserId(src.XboxUserId)
            {}

            UserXboxInfo(const rapidjson::Value& obj) : UserXboxInfo()
            {
                readFromValue(obj);
            }

            ~UserXboxInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (XboxUserId.length() > 0) { writer.String("XboxUserId"); writer.String(XboxUserId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator XboxUserId_member = obj.FindMember("XboxUserId");
                if (XboxUserId_member != obj.MemberEnd() && !XboxUserId_member->value.IsNull()) XboxUserId = XboxUserId_member->value.GetString();

                return true;
            }
        };

        struct UserCustomIdInfo : public PlayFabBaseModel
        {
            Aws::String CustomId;

            UserCustomIdInfo() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UserCustomIdInfo(const UserCustomIdInfo& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UserCustomIdInfo(const rapidjson::Value& obj) : UserCustomIdInfo()
            {
                readFromValue(obj);
            }

            ~UserCustomIdInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CustomId.length() > 0) { writer.String("CustomId"); writer.String(CustomId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

                return true;
            }
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            time_t Created;
            Aws::String Username;
            UserTitleInfo* TitleInfo;
            UserPrivateAccountInfo* PrivateInfo;
            UserFacebookInfo* FacebookInfo;
            UserSteamInfo* SteamInfo;
            UserGameCenterInfo* GameCenterInfo;
            UserIosDeviceInfo* IosDeviceInfo;
            UserAndroidDeviceInfo* AndroidDeviceInfo;
            UserKongregateInfo* KongregateInfo;
            UserTwitchInfo* TwitchInfo;
            UserPsnInfo* PsnInfo;
            UserGoogleInfo* GoogleInfo;
            UserXboxInfo* XboxInfo;
            UserCustomIdInfo* CustomIdInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                PlayFabId(),
                Created(0),
                Username(),
                TitleInfo(nullptr),
                PrivateInfo(nullptr),
                FacebookInfo(nullptr),
                SteamInfo(nullptr),
                GameCenterInfo(nullptr),
                IosDeviceInfo(nullptr),
                AndroidDeviceInfo(nullptr),
                KongregateInfo(nullptr),
                TwitchInfo(nullptr),
                PsnInfo(nullptr),
                GoogleInfo(nullptr),
                XboxInfo(nullptr),
                CustomIdInfo(nullptr)
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Created(src.Created),
                Username(src.Username),
                TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : nullptr),
                PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : nullptr),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : nullptr),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : nullptr),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : nullptr),
                IosDeviceInfo(src.IosDeviceInfo ? new UserIosDeviceInfo(*src.IosDeviceInfo) : nullptr),
                AndroidDeviceInfo(src.AndroidDeviceInfo ? new UserAndroidDeviceInfo(*src.AndroidDeviceInfo) : nullptr),
                KongregateInfo(src.KongregateInfo ? new UserKongregateInfo(*src.KongregateInfo) : nullptr),
                TwitchInfo(src.TwitchInfo ? new UserTwitchInfo(*src.TwitchInfo) : nullptr),
                PsnInfo(src.PsnInfo ? new UserPsnInfo(*src.PsnInfo) : nullptr),
                GoogleInfo(src.GoogleInfo ? new UserGoogleInfo(*src.GoogleInfo) : nullptr),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : nullptr),
                CustomIdInfo(src.CustomIdInfo ? new UserCustomIdInfo(*src.CustomIdInfo) : nullptr)
            {}

            UserAccountInfo(const rapidjson::Value& obj) : UserAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserAccountInfo()
            {
                if (TitleInfo != nullptr) delete TitleInfo;
                if (PrivateInfo != nullptr) delete PrivateInfo;
                if (FacebookInfo != nullptr) delete FacebookInfo;
                if (SteamInfo != nullptr) delete SteamInfo;
                if (GameCenterInfo != nullptr) delete GameCenterInfo;
                if (IosDeviceInfo != nullptr) delete IosDeviceInfo;
                if (AndroidDeviceInfo != nullptr) delete AndroidDeviceInfo;
                if (KongregateInfo != nullptr) delete KongregateInfo;
                if (TwitchInfo != nullptr) delete TwitchInfo;
                if (PsnInfo != nullptr) delete PsnInfo;
                if (GoogleInfo != nullptr) delete GoogleInfo;
                if (XboxInfo != nullptr) delete XboxInfo;
                if (CustomIdInfo != nullptr) delete CustomIdInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                writer.String("Created"); writeDatetime(Created, writer);
                if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
                if (TitleInfo != nullptr) { writer.String("TitleInfo"); TitleInfo->writeJSON(writer); }
                if (PrivateInfo != nullptr) { writer.String("PrivateInfo"); PrivateInfo->writeJSON(writer); }
                if (FacebookInfo != nullptr) { writer.String("FacebookInfo"); FacebookInfo->writeJSON(writer); }
                if (SteamInfo != nullptr) { writer.String("SteamInfo"); SteamInfo->writeJSON(writer); }
                if (GameCenterInfo != nullptr) { writer.String("GameCenterInfo"); GameCenterInfo->writeJSON(writer); }
                if (IosDeviceInfo != nullptr) { writer.String("IosDeviceInfo"); IosDeviceInfo->writeJSON(writer); }
                if (AndroidDeviceInfo != nullptr) { writer.String("AndroidDeviceInfo"); AndroidDeviceInfo->writeJSON(writer); }
                if (KongregateInfo != nullptr) { writer.String("KongregateInfo"); KongregateInfo->writeJSON(writer); }
                if (TwitchInfo != nullptr) { writer.String("TwitchInfo"); TwitchInfo->writeJSON(writer); }
                if (PsnInfo != nullptr) { writer.String("PsnInfo"); PsnInfo->writeJSON(writer); }
                if (GoogleInfo != nullptr) { writer.String("GoogleInfo"); GoogleInfo->writeJSON(writer); }
                if (XboxInfo != nullptr) { writer.String("XboxInfo"); XboxInfo->writeJSON(writer); }
                if (CustomIdInfo != nullptr) { writer.String("CustomIdInfo"); CustomIdInfo->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator TitleInfo_member = obj.FindMember("TitleInfo");
                if (TitleInfo_member != obj.MemberEnd() && !TitleInfo_member->value.IsNull()) TitleInfo = new UserTitleInfo(TitleInfo_member->value);
                const Value::ConstMemberIterator PrivateInfo_member = obj.FindMember("PrivateInfo");
                if (PrivateInfo_member != obj.MemberEnd() && !PrivateInfo_member->value.IsNull()) PrivateInfo = new UserPrivateAccountInfo(PrivateInfo_member->value);
                const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
                if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
                const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
                if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
                const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
                if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
                const Value::ConstMemberIterator IosDeviceInfo_member = obj.FindMember("IosDeviceInfo");
                if (IosDeviceInfo_member != obj.MemberEnd() && !IosDeviceInfo_member->value.IsNull()) IosDeviceInfo = new UserIosDeviceInfo(IosDeviceInfo_member->value);
                const Value::ConstMemberIterator AndroidDeviceInfo_member = obj.FindMember("AndroidDeviceInfo");
                if (AndroidDeviceInfo_member != obj.MemberEnd() && !AndroidDeviceInfo_member->value.IsNull()) AndroidDeviceInfo = new UserAndroidDeviceInfo(AndroidDeviceInfo_member->value);
                const Value::ConstMemberIterator KongregateInfo_member = obj.FindMember("KongregateInfo");
                if (KongregateInfo_member != obj.MemberEnd() && !KongregateInfo_member->value.IsNull()) KongregateInfo = new UserKongregateInfo(KongregateInfo_member->value);
                const Value::ConstMemberIterator TwitchInfo_member = obj.FindMember("TwitchInfo");
                if (TwitchInfo_member != obj.MemberEnd() && !TwitchInfo_member->value.IsNull()) TwitchInfo = new UserTwitchInfo(TwitchInfo_member->value);
                const Value::ConstMemberIterator PsnInfo_member = obj.FindMember("PsnInfo");
                if (PsnInfo_member != obj.MemberEnd() && !PsnInfo_member->value.IsNull()) PsnInfo = new UserPsnInfo(PsnInfo_member->value);
                const Value::ConstMemberIterator GoogleInfo_member = obj.FindMember("GoogleInfo");
                if (GoogleInfo_member != obj.MemberEnd() && !GoogleInfo_member->value.IsNull()) GoogleInfo = new UserGoogleInfo(GoogleInfo_member->value);
                const Value::ConstMemberIterator XboxInfo_member = obj.FindMember("XboxInfo");
                if (XboxInfo_member != obj.MemberEnd() && !XboxInfo_member->value.IsNull()) XboxInfo = new UserXboxInfo(XboxInfo_member->value);
                const Value::ConstMemberIterator CustomIdInfo_member = obj.FindMember("CustomIdInfo");
                if (CustomIdInfo_member != obj.MemberEnd() && !CustomIdInfo_member->value.IsNull()) CustomIdInfo = new UserCustomIdInfo(CustomIdInfo_member->value);

                return true;
            }
        };

        struct AuthenticateSessionTicketResult : public PlayFabBaseModel
        {
            UserAccountInfo* UserInfo;

            AuthenticateSessionTicketResult() :
                PlayFabBaseModel(),
                UserInfo(nullptr)
            {}

            AuthenticateSessionTicketResult(const AuthenticateSessionTicketResult& src) :
                PlayFabBaseModel(),
                UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : nullptr)
            {}

            AuthenticateSessionTicketResult(const rapidjson::Value& obj) : AuthenticateSessionTicketResult()
            {
                readFromValue(obj);
            }

            ~AuthenticateSessionTicketResult()
            {
                if (UserInfo != nullptr) delete UserInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UserInfo != nullptr) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
                if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

                return true;
            }
        };

        struct AwardSteamAchievementItem : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String AchievementName;
            bool Result;

            AwardSteamAchievementItem() :
                PlayFabBaseModel(),
                PlayFabId(),
                AchievementName(),
                Result(false)
            {}

            AwardSteamAchievementItem(const AwardSteamAchievementItem& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                AchievementName(src.AchievementName),
                Result(src.Result)
            {}

            AwardSteamAchievementItem(const rapidjson::Value& obj) : AwardSteamAchievementItem()
            {
                readFromValue(obj);
            }

            ~AwardSteamAchievementItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("AchievementName"); writer.String(AchievementName.c_str());
                writer.String("Result"); writer.Bool(Result);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator AchievementName_member = obj.FindMember("AchievementName");
                if (AchievementName_member != obj.MemberEnd() && !AchievementName_member->value.IsNull()) AchievementName = AchievementName_member->value.GetString();
                const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
                if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();

                return true;
            }
        };

        struct AwardSteamAchievementRequest : public PlayFabBaseModel
        {
            std::list<AwardSteamAchievementItem> Achievements;

            AwardSteamAchievementRequest() :
                PlayFabBaseModel(),
                Achievements()
            {}

            AwardSteamAchievementRequest(const AwardSteamAchievementRequest& src) :
                PlayFabBaseModel(),
                Achievements(src.Achievements)
            {}

            AwardSteamAchievementRequest(const rapidjson::Value& obj) : AwardSteamAchievementRequest()
            {
                readFromValue(obj);
            }

            ~AwardSteamAchievementRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Achievements");
    writer.StartArray();
    for (std::list<AwardSteamAchievementItem>::iterator iter = Achievements.begin(); iter != Achievements.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Achievements_member = obj.FindMember("Achievements");
    if (Achievements_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Achievements_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Achievements.push_back(AwardSteamAchievementItem(memberList[i]));
        }
    }

                return true;
            }
        };

        struct AwardSteamAchievementResult : public PlayFabBaseModel
        {
            std::list<AwardSteamAchievementItem> AchievementResults;

            AwardSteamAchievementResult() :
                PlayFabBaseModel(),
                AchievementResults()
            {}

            AwardSteamAchievementResult(const AwardSteamAchievementResult& src) :
                PlayFabBaseModel(),
                AchievementResults(src.AchievementResults)
            {}

            AwardSteamAchievementResult(const rapidjson::Value& obj) : AwardSteamAchievementResult()
            {
                readFromValue(obj);
            }

            ~AwardSteamAchievementResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!AchievementResults.empty()) {
    writer.String("AchievementResults");
    writer.StartArray();
    for (std::list<AwardSteamAchievementItem>::iterator iter = AchievementResults.begin(); iter != AchievementResults.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AchievementResults_member = obj.FindMember("AchievementResults");
    if (AchievementResults_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AchievementResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AchievementResults.push_back(AwardSteamAchievementItem(memberList[i]));
        }
    }

                return true;
            }
        };

        struct BanInfo : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String BanId;
            Aws::String IPAddress;
            Aws::String MACAddress;
            OptionalTime Created;
            OptionalTime Expires;
            Aws::String Reason;
            bool Active;

            BanInfo() :
                PlayFabBaseModel(),
                PlayFabId(),
                BanId(),
                IPAddress(),
                MACAddress(),
                Created(),
                Expires(),
                Reason(),
                Active(false)
            {}

            BanInfo(const BanInfo& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                BanId(src.BanId),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Created(src.Created),
                Expires(src.Expires),
                Reason(src.Reason),
                Active(src.Active)
            {}

            BanInfo(const rapidjson::Value& obj) : BanInfo()
            {
                readFromValue(obj);
            }

            ~BanInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (BanId.length() > 0) { writer.String("BanId"); writer.String(BanId.c_str()); }
                if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
                if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
                if (Created.notNull()) { writer.String("Created"); writeDatetime(Created, writer); }
                if (Expires.notNull()) { writer.String("Expires"); writeDatetime(Expires, writer); }
                if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
                writer.String("Active"); writer.Bool(Active);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator BanId_member = obj.FindMember("BanId");
                if (BanId_member != obj.MemberEnd() && !BanId_member->value.IsNull()) BanId = BanId_member->value.GetString();
                const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
                if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
                const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
                if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
                if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
                const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
                if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();

                return true;
            }
        };

        struct BanRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String IPAddress;
            Aws::String MACAddress;
            Aws::String Reason;
            OptionalUint32 DurationInHours;

            BanRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                IPAddress(),
                MACAddress(),
                Reason(),
                DurationInHours()
            {}

            BanRequest(const BanRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Reason(src.Reason),
                DurationInHours(src.DurationInHours)
            {}

            BanRequest(const rapidjson::Value& obj) : BanRequest()
            {
                readFromValue(obj);
            }

            ~BanRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
                if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
                if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
                if (DurationInHours.notNull()) { writer.String("DurationInHours"); writer.Uint(DurationInHours); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
                if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
                const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
                if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
                const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
                if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
                const Value::ConstMemberIterator DurationInHours_member = obj.FindMember("DurationInHours");
                if (DurationInHours_member != obj.MemberEnd() && !DurationInHours_member->value.IsNull()) DurationInHours = DurationInHours_member->value.GetUint();

                return true;
            }
        };

        struct BanUsersRequest : public PlayFabBaseModel
        {
            std::list<BanRequest> Bans;

            BanUsersRequest() :
                PlayFabBaseModel(),
                Bans()
            {}

            BanUsersRequest(const BanUsersRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans)
            {}

            BanUsersRequest(const rapidjson::Value& obj) : BanUsersRequest()
            {
                readFromValue(obj);
            }

            ~BanUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Bans");
    writer.StartArray();
    for (std::list<BanRequest>::iterator iter = Bans.begin(); iter != Bans.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Bans_member = obj.FindMember("Bans");
    if (Bans_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Bans_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Bans.push_back(BanRequest(memberList[i]));
        }
    }

                return true;
            }
        };

        struct BanUsersResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            BanUsersResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            BanUsersResult(const BanUsersResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            BanUsersResult(const rapidjson::Value& obj) : BanUsersResult()
            {
                readFromValue(obj);
            }

            ~BanUsersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct CatalogItemConsumableInfo : public PlayFabBaseModel
        {
            OptionalUint32 UsageCount;
            OptionalUint32 UsagePeriod;
            Aws::String UsagePeriodGroup;

            CatalogItemConsumableInfo() :
                PlayFabBaseModel(),
                UsageCount(),
                UsagePeriod(),
                UsagePeriodGroup()
            {}

            CatalogItemConsumableInfo(const CatalogItemConsumableInfo& src) :
                PlayFabBaseModel(),
                UsageCount(src.UsageCount),
                UsagePeriod(src.UsagePeriod),
                UsagePeriodGroup(src.UsagePeriodGroup)
            {}

            CatalogItemConsumableInfo(const rapidjson::Value& obj) : CatalogItemConsumableInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemConsumableInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UsageCount.notNull()) { writer.String("UsageCount"); writer.Uint(UsageCount); }
                if (UsagePeriod.notNull()) { writer.String("UsagePeriod"); writer.Uint(UsagePeriod); }
                if (UsagePeriodGroup.length() > 0) { writer.String("UsagePeriodGroup"); writer.String(UsagePeriodGroup.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UsageCount_member = obj.FindMember("UsageCount");
                if (UsageCount_member != obj.MemberEnd() && !UsageCount_member->value.IsNull()) UsageCount = UsageCount_member->value.GetUint();
                const Value::ConstMemberIterator UsagePeriod_member = obj.FindMember("UsagePeriod");
                if (UsagePeriod_member != obj.MemberEnd() && !UsagePeriod_member->value.IsNull()) UsagePeriod = UsagePeriod_member->value.GetUint();
                const Value::ConstMemberIterator UsagePeriodGroup_member = obj.FindMember("UsagePeriodGroup");
                if (UsagePeriodGroup_member != obj.MemberEnd() && !UsagePeriodGroup_member->value.IsNull()) UsagePeriodGroup = UsagePeriodGroup_member->value.GetString();

                return true;
            }
        };

        struct CatalogItemContainerInfo : public PlayFabBaseModel
        {
            Aws::String KeyItemId;
            std::list<Aws::String> ItemContents;
            std::list<Aws::String> ResultTableContents;
            std::map<Aws::String, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                KeyItemId(),
                ItemContents(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                KeyItemId(src.KeyItemId),
                ItemContents(src.ItemContents),
                ResultTableContents(src.ResultTableContents),
                VirtualCurrencyContents(src.VirtualCurrencyContents)
            {}

            CatalogItemContainerInfo(const rapidjson::Value& obj) : CatalogItemContainerInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemContainerInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (KeyItemId.length() > 0) { writer.String("KeyItemId"); writer.String(KeyItemId.c_str()); }
                if (!ItemContents.empty()) {
    writer.String("ItemContents");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = ItemContents.begin(); iter != ItemContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!ResultTableContents.empty()) {
    writer.String("ResultTableContents");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = ResultTableContents.begin(); iter != ResultTableContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!VirtualCurrencyContents.empty()) {
    writer.String("VirtualCurrencyContents");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = VirtualCurrencyContents.begin(); iter != VirtualCurrencyContents.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KeyItemId_member = obj.FindMember("KeyItemId");
                if (KeyItemId_member != obj.MemberEnd() && !KeyItemId_member->value.IsNull()) KeyItemId = KeyItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemContents_member = obj.FindMember("ItemContents");
    if (ItemContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemContents.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator ResultTableContents_member = obj.FindMember("ResultTableContents");
    if (ResultTableContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ResultTableContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ResultTableContents.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator VirtualCurrencyContents_member = obj.FindMember("VirtualCurrencyContents");
    if (VirtualCurrencyContents_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyContents_member->value.MemberBegin(); iter != VirtualCurrencyContents_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyContents[iter->name.GetString()] = iter->value.GetUint();
        }
    }

                return true;
            }
        };

        struct CatalogItemBundleInfo : public PlayFabBaseModel
        {
            std::list<Aws::String> BundledItems;
            std::list<Aws::String> BundledResultTables;
            std::map<Aws::String, Uint32> BundledVirtualCurrencies;

            CatalogItemBundleInfo() :
                PlayFabBaseModel(),
                BundledItems(),
                BundledResultTables(),
                BundledVirtualCurrencies()
            {}

            CatalogItemBundleInfo(const CatalogItemBundleInfo& src) :
                PlayFabBaseModel(),
                BundledItems(src.BundledItems),
                BundledResultTables(src.BundledResultTables),
                BundledVirtualCurrencies(src.BundledVirtualCurrencies)
            {}

            CatalogItemBundleInfo(const rapidjson::Value& obj) : CatalogItemBundleInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemBundleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BundledItems.empty()) {
    writer.String("BundledItems");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = BundledItems.begin(); iter != BundledItems.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!BundledResultTables.empty()) {
    writer.String("BundledResultTables");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = BundledResultTables.begin(); iter != BundledResultTables.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!BundledVirtualCurrencies.empty()) {
    writer.String("BundledVirtualCurrencies");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = BundledVirtualCurrencies.begin(); iter != BundledVirtualCurrencies.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BundledItems_member = obj.FindMember("BundledItems");
    if (BundledItems_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundledItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundledItems.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator BundledResultTables_member = obj.FindMember("BundledResultTables");
    if (BundledResultTables_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundledResultTables_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundledResultTables.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator BundledVirtualCurrencies_member = obj.FindMember("BundledVirtualCurrencies");
    if (BundledVirtualCurrencies_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = BundledVirtualCurrencies_member->value.MemberBegin(); iter != BundledVirtualCurrencies_member->value.MemberEnd(); ++iter) {
            BundledVirtualCurrencies[iter->name.GetString()] = iter->value.GetUint();
        }
    }

                return true;
            }
        };

        struct CatalogItem : public PlayFabBaseModel
        {
            Aws::String ItemId;
            Aws::String ItemClass;
            Aws::String CatalogVersion;
            Aws::String DisplayName;
            Aws::String Description;
            std::map<Aws::String, Uint32> VirtualCurrencyPrices;
            std::map<Aws::String, Uint32> RealCurrencyPrices;
            std::list<Aws::String> Tags;
            Aws::String CustomData;
            CatalogItemConsumableInfo* Consumable;
            CatalogItemContainerInfo* Container;
            CatalogItemBundleInfo* Bundle;
            bool CanBecomeCharacter;
            bool IsStackable;
            bool IsTradable;
            Aws::String ItemImageUrl;
            bool IsLimitedEdition;
            Int32 InitialLimitedEditionCount;

            CatalogItem() :
                PlayFabBaseModel(),
                ItemId(),
                ItemClass(),
                CatalogVersion(),
                DisplayName(),
                Description(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices(),
                Tags(),
                CustomData(),
                Consumable(nullptr),
                Container(nullptr),
                Bundle(nullptr),
                CanBecomeCharacter(false),
                IsStackable(false),
                IsTradable(false),
                ItemImageUrl(),
                IsLimitedEdition(false),
                InitialLimitedEditionCount(0)
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemClass(src.ItemClass),
                CatalogVersion(src.CatalogVersion),
                DisplayName(src.DisplayName),
                Description(src.Description),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                CustomData(src.CustomData),
                Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : nullptr),
                Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : nullptr),
                Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : nullptr),
                CanBecomeCharacter(src.CanBecomeCharacter),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemImageUrl(src.ItemImageUrl),
                IsLimitedEdition(src.IsLimitedEdition),
                InitialLimitedEditionCount(src.InitialLimitedEditionCount)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem()
            {
                if (Consumable != nullptr) delete Consumable;
                if (Container != nullptr) delete Container;
                if (Bundle != nullptr) delete Bundle;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemId"); writer.String(ItemId.c_str());
                if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
                if (!VirtualCurrencyPrices.empty()) {
    writer.String("VirtualCurrencyPrices");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                if (!RealCurrencyPrices.empty()) {
    writer.String("RealCurrencyPrices");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (CustomData.length() > 0) { writer.String("CustomData"); writer.String(CustomData.c_str()); }
                if (Consumable != nullptr) { writer.String("Consumable"); Consumable->writeJSON(writer); }
                if (Container != nullptr) { writer.String("Container"); Container->writeJSON(writer); }
                if (Bundle != nullptr) { writer.String("Bundle"); Bundle->writeJSON(writer); }
                writer.String("CanBecomeCharacter"); writer.Bool(CanBecomeCharacter);
                writer.String("IsStackable"); writer.Bool(IsStackable);
                writer.String("IsTradable"); writer.Bool(IsTradable);
                if (ItemImageUrl.length() > 0) { writer.String("ItemImageUrl"); writer.String(ItemImageUrl.c_str()); }
                writer.String("IsLimitedEdition"); writer.Bool(IsLimitedEdition);
                writer.String("InitialLimitedEditionCount"); writer.Int(InitialLimitedEditionCount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
    if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
    if (RealCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
            RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
                if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = CustomData_member->value.GetString();
                const Value::ConstMemberIterator Consumable_member = obj.FindMember("Consumable");
                if (Consumable_member != obj.MemberEnd() && !Consumable_member->value.IsNull()) Consumable = new CatalogItemConsumableInfo(Consumable_member->value);
                const Value::ConstMemberIterator Container_member = obj.FindMember("Container");
                if (Container_member != obj.MemberEnd() && !Container_member->value.IsNull()) Container = new CatalogItemContainerInfo(Container_member->value);
                const Value::ConstMemberIterator Bundle_member = obj.FindMember("Bundle");
                if (Bundle_member != obj.MemberEnd() && !Bundle_member->value.IsNull()) Bundle = new CatalogItemBundleInfo(Bundle_member->value);
                const Value::ConstMemberIterator CanBecomeCharacter_member = obj.FindMember("CanBecomeCharacter");
                if (CanBecomeCharacter_member != obj.MemberEnd() && !CanBecomeCharacter_member->value.IsNull()) CanBecomeCharacter = CanBecomeCharacter_member->value.GetBool();
                const Value::ConstMemberIterator IsStackable_member = obj.FindMember("IsStackable");
                if (IsStackable_member != obj.MemberEnd() && !IsStackable_member->value.IsNull()) IsStackable = IsStackable_member->value.GetBool();
                const Value::ConstMemberIterator IsTradable_member = obj.FindMember("IsTradable");
                if (IsTradable_member != obj.MemberEnd() && !IsTradable_member->value.IsNull()) IsTradable = IsTradable_member->value.GetBool();
                const Value::ConstMemberIterator ItemImageUrl_member = obj.FindMember("ItemImageUrl");
                if (ItemImageUrl_member != obj.MemberEnd() && !ItemImageUrl_member->value.IsNull()) ItemImageUrl = ItemImageUrl_member->value.GetString();
                const Value::ConstMemberIterator IsLimitedEdition_member = obj.FindMember("IsLimitedEdition");
                if (IsLimitedEdition_member != obj.MemberEnd() && !IsLimitedEdition_member->value.IsNull()) IsLimitedEdition = IsLimitedEdition_member->value.GetBool();
                const Value::ConstMemberIterator InitialLimitedEditionCount_member = obj.FindMember("InitialLimitedEditionCount");
                if (InitialLimitedEditionCount_member != obj.MemberEnd() && !InitialLimitedEditionCount_member->value.IsNull()) InitialLimitedEditionCount = InitialLimitedEditionCount_member->value.GetInt();

                return true;
            }
        };

        struct ItemInstance : public PlayFabBaseModel
        {
            Aws::String ItemId;
            Aws::String ItemInstanceId;
            Aws::String ItemClass;
            OptionalTime PurchaseDate;
            OptionalTime Expiration;
            OptionalInt32 RemainingUses;
            OptionalInt32 UsesIncrementedBy;
            Aws::String Annotation;
            Aws::String CatalogVersion;
            Aws::String BundleParent;
            Aws::String DisplayName;
            Aws::String UnitCurrency;
            Uint32 UnitPrice;
            std::list<Aws::String> BundleContents;
            std::map<Aws::String, Aws::String> CustomData;

            ItemInstance() :
                PlayFabBaseModel(),
                ItemId(),
                ItemInstanceId(),
                ItemClass(),
                PurchaseDate(),
                Expiration(),
                RemainingUses(),
                UsesIncrementedBy(),
                Annotation(),
                CatalogVersion(),
                BundleParent(),
                DisplayName(),
                UnitCurrency(),
                UnitPrice(0),
                BundleContents(),
                CustomData()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                ItemClass(src.ItemClass),
                PurchaseDate(src.PurchaseDate),
                Expiration(src.Expiration),
                RemainingUses(src.RemainingUses),
                UsesIncrementedBy(src.UsesIncrementedBy),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                BundleParent(src.BundleParent),
                DisplayName(src.DisplayName),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                BundleContents(src.BundleContents),
                CustomData(src.CustomData)
            {}

            ItemInstance(const rapidjson::Value& obj) : ItemInstance()
            {
                readFromValue(obj);
            }

            ~ItemInstance()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
                if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
                if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
                if (PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
                if (Expiration.notNull()) { writer.String("Expiration"); writeDatetime(Expiration, writer); }
                if (RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
                if (UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
                if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                if (BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
                writer.String("UnitPrice"); writer.Uint(UnitPrice);
                if (!BundleContents.empty()) {
    writer.String("BundleContents");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!CustomData.empty()) {
    writer.String("CustomData");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
                const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
                if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
                const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
                if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator BundleParent_member = obj.FindMember("BundleParent");
                if (BundleParent_member != obj.MemberEnd() && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
                if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
                const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
                if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
                const Value::ConstMemberIterator BundleContents_member = obj.FindMember("BundleContents");
    if (BundleContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundleContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundleContents.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
            CustomData[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct CharacterInventory : public PlayFabBaseModel
        {
            Aws::String CharacterId;
            std::list<ItemInstance> Inventory;

            CharacterInventory() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory()
            {}

            CharacterInventory(const CharacterInventory& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory)
            {}

            CharacterInventory(const rapidjson::Value& obj) : CharacterInventory()
            {
                readFromValue(obj);
            }

            ~CharacterInventory()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                if (!Inventory.empty()) {
    writer.String("Inventory");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }

                return true;
            }
        };

        struct CharacterLeaderboardEntry : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String CharacterName;
            Aws::String DisplayName;
            Aws::String CharacterType;
            Int32 StatValue;
            Int32 Position;

            CharacterLeaderboardEntry() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                CharacterName(),
                DisplayName(),
                CharacterType(),
                StatValue(0),
                Position(0)
            {}

            CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                DisplayName(src.DisplayName),
                CharacterType(src.CharacterType),
                StatValue(src.StatValue),
                Position(src.Position)
            {}

            CharacterLeaderboardEntry(const rapidjson::Value& obj) : CharacterLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~CharacterLeaderboardEntry()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                if (CharacterName.length() > 0) { writer.String("CharacterName"); writer.String(CharacterName.c_str()); }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
                writer.String("StatValue"); writer.Int(StatValue);
                writer.String("Position"); writer.Int(Position);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
                if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();
                const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
                if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();

                return true;
            }
        };

        struct CharacterResult : public PlayFabBaseModel
        {
            Aws::String CharacterId;
            Aws::String CharacterName;
            Aws::String CharacterType;

            CharacterResult() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType()
            {}

            CharacterResult(const CharacterResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType)
            {}

            CharacterResult(const rapidjson::Value& obj) : CharacterResult()
            {
                readFromValue(obj);
            }

            ~CharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                if (CharacterName.length() > 0) { writer.String("CharacterName"); writer.String(CharacterName.c_str()); }
                if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();

                return true;
            }
        };

        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        inline void writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CloudScriptRevisionOptionLive: writer.String("Live"); break;
            case CloudScriptRevisionOptionLatest: writer.String("Latest"); break;
            case CloudScriptRevisionOptionSpecific: writer.String("Specific"); break;

            }
        }

        inline CloudScriptRevisionOption readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, CloudScriptRevisionOption> _CloudScriptRevisionOptionMap;
            if (_CloudScriptRevisionOptionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CloudScriptRevisionOptionMap["Live"] = CloudScriptRevisionOptionLive;
                _CloudScriptRevisionOptionMap["Latest"] = CloudScriptRevisionOptionLatest;
                _CloudScriptRevisionOptionMap["Specific"] = CloudScriptRevisionOptionSpecific;

            }

            auto output = _CloudScriptRevisionOptionMap.find(obj.GetString());
            if (output != _CloudScriptRevisionOptionMap.end())
                return output->second;

            return CloudScriptRevisionOptionLive; // Basically critical fail
        }

        struct ConsumeItemRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String ItemInstanceId;
            Int32 ConsumeCount;
            Aws::String CharacterId;

            ConsumeItemRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                ItemInstanceId(),
                ConsumeCount(0),
                CharacterId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ItemInstanceId(src.ItemInstanceId),
                ConsumeCount(src.ConsumeCount),
                CharacterId(src.CharacterId)
            {}

            ConsumeItemRequest(const rapidjson::Value& obj) : ConsumeItemRequest()
            {
                readFromValue(obj);
            }

            ~ConsumeItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
                writer.String("ConsumeCount"); writer.Int(ConsumeCount);
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator ConsumeCount_member = obj.FindMember("ConsumeCount");
                if (ConsumeCount_member != obj.MemberEnd() && !ConsumeCount_member->value.IsNull()) ConsumeCount = ConsumeCount_member->value.GetInt();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct ConsumeItemResult : public PlayFabBaseModel
        {
            Aws::String ItemInstanceId;
            Int32 RemainingUses;

            ConsumeItemResult() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                RemainingUses(0)
            {}

            ConsumeItemResult(const ConsumeItemResult& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ConsumeItemResult(const rapidjson::Value& obj) : ConsumeItemResult()
            {
                readFromValue(obj);
            }

            ~ConsumeItemResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
                writer.String("RemainingUses"); writer.Int(RemainingUses);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();

                return true;
            }
        };

        enum ContinentCode
        {
            ContinentCodeAF,
            ContinentCodeAN,
            ContinentCodeAS,
            ContinentCodeEU,
            ContinentCodeNA,
            ContinentCodeOC,
            ContinentCodeSA
        };

        inline void writeContinentCodeEnumJSON(ContinentCode enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ContinentCodeAF: writer.String("AF"); break;
            case ContinentCodeAN: writer.String("AN"); break;
            case ContinentCodeAS: writer.String("AS"); break;
            case ContinentCodeEU: writer.String("EU"); break;
            case ContinentCodeNA: writer.String("NA"); break;
            case ContinentCodeOC: writer.String("OC"); break;
            case ContinentCodeSA: writer.String("SA"); break;

            }
        }

        inline ContinentCode readContinentCodeFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, ContinentCode> _ContinentCodeMap;
            if (_ContinentCodeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ContinentCodeMap["AF"] = ContinentCodeAF;
                _ContinentCodeMap["AN"] = ContinentCodeAN;
                _ContinentCodeMap["AS"] = ContinentCodeAS;
                _ContinentCodeMap["EU"] = ContinentCodeEU;
                _ContinentCodeMap["NA"] = ContinentCodeNA;
                _ContinentCodeMap["OC"] = ContinentCodeOC;
                _ContinentCodeMap["SA"] = ContinentCodeSA;

            }

            auto output = _ContinentCodeMap.find(obj.GetString());
            if (output != _ContinentCodeMap.end())
                return output->second;

            return ContinentCodeAF; // Basically critical fail
        }

        enum CountryCode
        {
            CountryCodeAF,
            CountryCodeAX,
            CountryCodeAL,
            CountryCodeDZ,
            CountryCodeAS,
            CountryCodeAD,
            CountryCodeAO,
            CountryCodeAI,
            CountryCodeAQ,
            CountryCodeAG,
            CountryCodeAR,
            CountryCodeAM,
            CountryCodeAW,
            CountryCodeAU,
            CountryCodeAT,
            CountryCodeAZ,
            CountryCodeBS,
            CountryCodeBH,
            CountryCodeBD,
            CountryCodeBB,
            CountryCodeBY,
            CountryCodeBE,
            CountryCodeBZ,
            CountryCodeBJ,
            CountryCodeBM,
            CountryCodeBT,
            CountryCodeBO,
            CountryCodeBQ,
            CountryCodeBA,
            CountryCodeBW,
            CountryCodeBV,
            CountryCodeBR,
            CountryCodeIO,
            CountryCodeBN,
            CountryCodeBG,
            CountryCodeBF,
            CountryCodeBI,
            CountryCodeKH,
            CountryCodeCM,
            CountryCodeCA,
            CountryCodeCV,
            CountryCodeKY,
            CountryCodeCF,
            CountryCodeTD,
            CountryCodeCL,
            CountryCodeCN,
            CountryCodeCX,
            CountryCodeCC,
            CountryCodeCO,
            CountryCodeKM,
            CountryCodeCG,
            CountryCodeCD,
            CountryCodeCK,
            CountryCodeCR,
            CountryCodeCI,
            CountryCodeHR,
            CountryCodeCU,
            CountryCodeCW,
            CountryCodeCY,
            CountryCodeCZ,
            CountryCodeDK,
            CountryCodeDJ,
            CountryCodeDM,
            CountryCodeDO,
            CountryCodeEC,
            CountryCodeEG,
            CountryCodeSV,
            CountryCodeGQ,
            CountryCodeER,
            CountryCodeEE,
            CountryCodeET,
            CountryCodeFK,
            CountryCodeFO,
            CountryCodeFJ,
            CountryCodeFI,
            CountryCodeFR,
            CountryCodeGF,
            CountryCodePF,
            CountryCodeTF,
            CountryCodeGA,
            CountryCodeGM,
            CountryCodeGE,
            CountryCodeDE,
            CountryCodeGH,
            CountryCodeGI,
            CountryCodeGR,
            CountryCodeGL,
            CountryCodeGD,
            CountryCodeGP,
            CountryCodeGU,
            CountryCodeGT,
            CountryCodeGG,
            CountryCodeGN,
            CountryCodeGW,
            CountryCodeGY,
            CountryCodeHT,
            CountryCodeHM,
            CountryCodeVA,
            CountryCodeHN,
            CountryCodeHK,
            CountryCodeHU,
            CountryCodeIS,
            CountryCodeIN,
            CountryCodeID,
            CountryCodeIR,
            CountryCodeIQ,
            CountryCodeIE,
            CountryCodeIM,
            CountryCodeIL,
            CountryCodeIT,
            CountryCodeJM,
            CountryCodeJP,
            CountryCodeJE,
            CountryCodeJO,
            CountryCodeKZ,
            CountryCodeKE,
            CountryCodeKI,
            CountryCodeKP,
            CountryCodeKR,
            CountryCodeKW,
            CountryCodeKG,
            CountryCodeLA,
            CountryCodeLV,
            CountryCodeLB,
            CountryCodeLS,
            CountryCodeLR,
            CountryCodeLY,
            CountryCodeLI,
            CountryCodeLT,
            CountryCodeLU,
            CountryCodeMO,
            CountryCodeMK,
            CountryCodeMG,
            CountryCodeMW,
            CountryCodeMY,
            CountryCodeMV,
            CountryCodeML,
            CountryCodeMT,
            CountryCodeMH,
            CountryCodeMQ,
            CountryCodeMR,
            CountryCodeMU,
            CountryCodeYT,
            CountryCodeMX,
            CountryCodeFM,
            CountryCodeMD,
            CountryCodeMC,
            CountryCodeMN,
            CountryCodeME,
            CountryCodeMS,
            CountryCodeMA,
            CountryCodeMZ,
            CountryCodeMM,
            CountryCodeNA,
            CountryCodeNR,
            CountryCodeNP,
            CountryCodeNL,
            CountryCodeNC,
            CountryCodeNZ,
            CountryCodeNI,
            CountryCodeNE,
            CountryCodeNG,
            CountryCodeNU,
            CountryCodeNF,
            CountryCodeMP,
            CountryCodeNO,
            CountryCodeOM,
            CountryCodePK,
            CountryCodePW,
            CountryCodePS,
            CountryCodePA,
            CountryCodePG,
            CountryCodePY,
            CountryCodePE,
            CountryCodePH,
            CountryCodePN,
            CountryCodePL,
            CountryCodePT,
            CountryCodePR,
            CountryCodeQA,
            CountryCodeRE,
            CountryCodeRO,
            CountryCodeRU,
            CountryCodeRW,
            CountryCodeBL,
            CountryCodeSH,
            CountryCodeKN,
            CountryCodeLC,
            CountryCodeMF,
            CountryCodePM,
            CountryCodeVC,
            CountryCodeWS,
            CountryCodeSM,
            CountryCodeST,
            CountryCodeSA,
            CountryCodeSN,
            CountryCodeRS,
            CountryCodeSC,
            CountryCodeSL,
            CountryCodeSG,
            CountryCodeSX,
            CountryCodeSK,
            CountryCodeSI,
            CountryCodeSB,
            CountryCodeSO,
            CountryCodeZA,
            CountryCodeGS,
            CountryCodeSS,
            CountryCodeES,
            CountryCodeLK,
            CountryCodeSD,
            CountryCodeSR,
            CountryCodeSJ,
            CountryCodeSZ,
            CountryCodeSE,
            CountryCodeCH,
            CountryCodeSY,
            CountryCodeTW,
            CountryCodeTJ,
            CountryCodeTZ,
            CountryCodeTH,
            CountryCodeTL,
            CountryCodeTG,
            CountryCodeTK,
            CountryCodeTO,
            CountryCodeTT,
            CountryCodeTN,
            CountryCodeTR,
            CountryCodeTM,
            CountryCodeTC,
            CountryCodeTV,
            CountryCodeUG,
            CountryCodeUA,
            CountryCodeAE,
            CountryCodeGB,
            CountryCodeUS,
            CountryCodeUM,
            CountryCodeUY,
            CountryCodeUZ,
            CountryCodeVU,
            CountryCodeVE,
            CountryCodeVN,
            CountryCodeVG,
            CountryCodeVI,
            CountryCodeWF,
            CountryCodeEH,
            CountryCodeYE,
            CountryCodeZM,
            CountryCodeZW
        };

        inline void writeCountryCodeEnumJSON(CountryCode enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CountryCodeAF: writer.String("AF"); break;
            case CountryCodeAX: writer.String("AX"); break;
            case CountryCodeAL: writer.String("AL"); break;
            case CountryCodeDZ: writer.String("DZ"); break;
            case CountryCodeAS: writer.String("AS"); break;
            case CountryCodeAD: writer.String("AD"); break;
            case CountryCodeAO: writer.String("AO"); break;
            case CountryCodeAI: writer.String("AI"); break;
            case CountryCodeAQ: writer.String("AQ"); break;
            case CountryCodeAG: writer.String("AG"); break;
            case CountryCodeAR: writer.String("AR"); break;
            case CountryCodeAM: writer.String("AM"); break;
            case CountryCodeAW: writer.String("AW"); break;
            case CountryCodeAU: writer.String("AU"); break;
            case CountryCodeAT: writer.String("AT"); break;
            case CountryCodeAZ: writer.String("AZ"); break;
            case CountryCodeBS: writer.String("BS"); break;
            case CountryCodeBH: writer.String("BH"); break;
            case CountryCodeBD: writer.String("BD"); break;
            case CountryCodeBB: writer.String("BB"); break;
            case CountryCodeBY: writer.String("BY"); break;
            case CountryCodeBE: writer.String("BE"); break;
            case CountryCodeBZ: writer.String("BZ"); break;
            case CountryCodeBJ: writer.String("BJ"); break;
            case CountryCodeBM: writer.String("BM"); break;
            case CountryCodeBT: writer.String("BT"); break;
            case CountryCodeBO: writer.String("BO"); break;
            case CountryCodeBQ: writer.String("BQ"); break;
            case CountryCodeBA: writer.String("BA"); break;
            case CountryCodeBW: writer.String("BW"); break;
            case CountryCodeBV: writer.String("BV"); break;
            case CountryCodeBR: writer.String("BR"); break;
            case CountryCodeIO: writer.String("IO"); break;
            case CountryCodeBN: writer.String("BN"); break;
            case CountryCodeBG: writer.String("BG"); break;
            case CountryCodeBF: writer.String("BF"); break;
            case CountryCodeBI: writer.String("BI"); break;
            case CountryCodeKH: writer.String("KH"); break;
            case CountryCodeCM: writer.String("CM"); break;
            case CountryCodeCA: writer.String("CA"); break;
            case CountryCodeCV: writer.String("CV"); break;
            case CountryCodeKY: writer.String("KY"); break;
            case CountryCodeCF: writer.String("CF"); break;
            case CountryCodeTD: writer.String("TD"); break;
            case CountryCodeCL: writer.String("CL"); break;
            case CountryCodeCN: writer.String("CN"); break;
            case CountryCodeCX: writer.String("CX"); break;
            case CountryCodeCC: writer.String("CC"); break;
            case CountryCodeCO: writer.String("CO"); break;
            case CountryCodeKM: writer.String("KM"); break;
            case CountryCodeCG: writer.String("CG"); break;
            case CountryCodeCD: writer.String("CD"); break;
            case CountryCodeCK: writer.String("CK"); break;
            case CountryCodeCR: writer.String("CR"); break;
            case CountryCodeCI: writer.String("CI"); break;
            case CountryCodeHR: writer.String("HR"); break;
            case CountryCodeCU: writer.String("CU"); break;
            case CountryCodeCW: writer.String("CW"); break;
            case CountryCodeCY: writer.String("CY"); break;
            case CountryCodeCZ: writer.String("CZ"); break;
            case CountryCodeDK: writer.String("DK"); break;
            case CountryCodeDJ: writer.String("DJ"); break;
            case CountryCodeDM: writer.String("DM"); break;
            case CountryCodeDO: writer.String("DO"); break;
            case CountryCodeEC: writer.String("EC"); break;
            case CountryCodeEG: writer.String("EG"); break;
            case CountryCodeSV: writer.String("SV"); break;
            case CountryCodeGQ: writer.String("GQ"); break;
            case CountryCodeER: writer.String("ER"); break;
            case CountryCodeEE: writer.String("EE"); break;
            case CountryCodeET: writer.String("ET"); break;
            case CountryCodeFK: writer.String("FK"); break;
            case CountryCodeFO: writer.String("FO"); break;
            case CountryCodeFJ: writer.String("FJ"); break;
            case CountryCodeFI: writer.String("FI"); break;
            case CountryCodeFR: writer.String("FR"); break;
            case CountryCodeGF: writer.String("GF"); break;
            case CountryCodePF: writer.String("PF"); break;
            case CountryCodeTF: writer.String("TF"); break;
            case CountryCodeGA: writer.String("GA"); break;
            case CountryCodeGM: writer.String("GM"); break;
            case CountryCodeGE: writer.String("GE"); break;
            case CountryCodeDE: writer.String("DE"); break;
            case CountryCodeGH: writer.String("GH"); break;
            case CountryCodeGI: writer.String("GI"); break;
            case CountryCodeGR: writer.String("GR"); break;
            case CountryCodeGL: writer.String("GL"); break;
            case CountryCodeGD: writer.String("GD"); break;
            case CountryCodeGP: writer.String("GP"); break;
            case CountryCodeGU: writer.String("GU"); break;
            case CountryCodeGT: writer.String("GT"); break;
            case CountryCodeGG: writer.String("GG"); break;
            case CountryCodeGN: writer.String("GN"); break;
            case CountryCodeGW: writer.String("GW"); break;
            case CountryCodeGY: writer.String("GY"); break;
            case CountryCodeHT: writer.String("HT"); break;
            case CountryCodeHM: writer.String("HM"); break;
            case CountryCodeVA: writer.String("VA"); break;
            case CountryCodeHN: writer.String("HN"); break;
            case CountryCodeHK: writer.String("HK"); break;
            case CountryCodeHU: writer.String("HU"); break;
            case CountryCodeIS: writer.String("IS"); break;
            case CountryCodeIN: writer.String("IN"); break;
            case CountryCodeID: writer.String("ID"); break;
            case CountryCodeIR: writer.String("IR"); break;
            case CountryCodeIQ: writer.String("IQ"); break;
            case CountryCodeIE: writer.String("IE"); break;
            case CountryCodeIM: writer.String("IM"); break;
            case CountryCodeIL: writer.String("IL"); break;
            case CountryCodeIT: writer.String("IT"); break;
            case CountryCodeJM: writer.String("JM"); break;
            case CountryCodeJP: writer.String("JP"); break;
            case CountryCodeJE: writer.String("JE"); break;
            case CountryCodeJO: writer.String("JO"); break;
            case CountryCodeKZ: writer.String("KZ"); break;
            case CountryCodeKE: writer.String("KE"); break;
            case CountryCodeKI: writer.String("KI"); break;
            case CountryCodeKP: writer.String("KP"); break;
            case CountryCodeKR: writer.String("KR"); break;
            case CountryCodeKW: writer.String("KW"); break;
            case CountryCodeKG: writer.String("KG"); break;
            case CountryCodeLA: writer.String("LA"); break;
            case CountryCodeLV: writer.String("LV"); break;
            case CountryCodeLB: writer.String("LB"); break;
            case CountryCodeLS: writer.String("LS"); break;
            case CountryCodeLR: writer.String("LR"); break;
            case CountryCodeLY: writer.String("LY"); break;
            case CountryCodeLI: writer.String("LI"); break;
            case CountryCodeLT: writer.String("LT"); break;
            case CountryCodeLU: writer.String("LU"); break;
            case CountryCodeMO: writer.String("MO"); break;
            case CountryCodeMK: writer.String("MK"); break;
            case CountryCodeMG: writer.String("MG"); break;
            case CountryCodeMW: writer.String("MW"); break;
            case CountryCodeMY: writer.String("MY"); break;
            case CountryCodeMV: writer.String("MV"); break;
            case CountryCodeML: writer.String("ML"); break;
            case CountryCodeMT: writer.String("MT"); break;
            case CountryCodeMH: writer.String("MH"); break;
            case CountryCodeMQ: writer.String("MQ"); break;
            case CountryCodeMR: writer.String("MR"); break;
            case CountryCodeMU: writer.String("MU"); break;
            case CountryCodeYT: writer.String("YT"); break;
            case CountryCodeMX: writer.String("MX"); break;
            case CountryCodeFM: writer.String("FM"); break;
            case CountryCodeMD: writer.String("MD"); break;
            case CountryCodeMC: writer.String("MC"); break;
            case CountryCodeMN: writer.String("MN"); break;
            case CountryCodeME: writer.String("ME"); break;
            case CountryCodeMS: writer.String("MS"); break;
            case CountryCodeMA: writer.String("MA"); break;
            case CountryCodeMZ: writer.String("MZ"); break;
            case CountryCodeMM: writer.String("MM"); break;
            case CountryCodeNA: writer.String("NA"); break;
            case CountryCodeNR: writer.String("NR"); break;
            case CountryCodeNP: writer.String("NP"); break;
            case CountryCodeNL: writer.String("NL"); break;
            case CountryCodeNC: writer.String("NC"); break;
            case CountryCodeNZ: writer.String("NZ"); break;
            case CountryCodeNI: writer.String("NI"); break;
            case CountryCodeNE: writer.String("NE"); break;
            case CountryCodeNG: writer.String("NG"); break;
            case CountryCodeNU: writer.String("NU"); break;
            case CountryCodeNF: writer.String("NF"); break;
            case CountryCodeMP: writer.String("MP"); break;
            case CountryCodeNO: writer.String("NO"); break;
            case CountryCodeOM: writer.String("OM"); break;
            case CountryCodePK: writer.String("PK"); break;
            case CountryCodePW: writer.String("PW"); break;
            case CountryCodePS: writer.String("PS"); break;
            case CountryCodePA: writer.String("PA"); break;
            case CountryCodePG: writer.String("PG"); break;
            case CountryCodePY: writer.String("PY"); break;
            case CountryCodePE: writer.String("PE"); break;
            case CountryCodePH: writer.String("PH"); break;
            case CountryCodePN: writer.String("PN"); break;
            case CountryCodePL: writer.String("PL"); break;
            case CountryCodePT: writer.String("PT"); break;
            case CountryCodePR: writer.String("PR"); break;
            case CountryCodeQA: writer.String("QA"); break;
            case CountryCodeRE: writer.String("RE"); break;
            case CountryCodeRO: writer.String("RO"); break;
            case CountryCodeRU: writer.String("RU"); break;
            case CountryCodeRW: writer.String("RW"); break;
            case CountryCodeBL: writer.String("BL"); break;
            case CountryCodeSH: writer.String("SH"); break;
            case CountryCodeKN: writer.String("KN"); break;
            case CountryCodeLC: writer.String("LC"); break;
            case CountryCodeMF: writer.String("MF"); break;
            case CountryCodePM: writer.String("PM"); break;
            case CountryCodeVC: writer.String("VC"); break;
            case CountryCodeWS: writer.String("WS"); break;
            case CountryCodeSM: writer.String("SM"); break;
            case CountryCodeST: writer.String("ST"); break;
            case CountryCodeSA: writer.String("SA"); break;
            case CountryCodeSN: writer.String("SN"); break;
            case CountryCodeRS: writer.String("RS"); break;
            case CountryCodeSC: writer.String("SC"); break;
            case CountryCodeSL: writer.String("SL"); break;
            case CountryCodeSG: writer.String("SG"); break;
            case CountryCodeSX: writer.String("SX"); break;
            case CountryCodeSK: writer.String("SK"); break;
            case CountryCodeSI: writer.String("SI"); break;
            case CountryCodeSB: writer.String("SB"); break;
            case CountryCodeSO: writer.String("SO"); break;
            case CountryCodeZA: writer.String("ZA"); break;
            case CountryCodeGS: writer.String("GS"); break;
            case CountryCodeSS: writer.String("SS"); break;
            case CountryCodeES: writer.String("ES"); break;
            case CountryCodeLK: writer.String("LK"); break;
            case CountryCodeSD: writer.String("SD"); break;
            case CountryCodeSR: writer.String("SR"); break;
            case CountryCodeSJ: writer.String("SJ"); break;
            case CountryCodeSZ: writer.String("SZ"); break;
            case CountryCodeSE: writer.String("SE"); break;
            case CountryCodeCH: writer.String("CH"); break;
            case CountryCodeSY: writer.String("SY"); break;
            case CountryCodeTW: writer.String("TW"); break;
            case CountryCodeTJ: writer.String("TJ"); break;
            case CountryCodeTZ: writer.String("TZ"); break;
            case CountryCodeTH: writer.String("TH"); break;
            case CountryCodeTL: writer.String("TL"); break;
            case CountryCodeTG: writer.String("TG"); break;
            case CountryCodeTK: writer.String("TK"); break;
            case CountryCodeTO: writer.String("TO"); break;
            case CountryCodeTT: writer.String("TT"); break;
            case CountryCodeTN: writer.String("TN"); break;
            case CountryCodeTR: writer.String("TR"); break;
            case CountryCodeTM: writer.String("TM"); break;
            case CountryCodeTC: writer.String("TC"); break;
            case CountryCodeTV: writer.String("TV"); break;
            case CountryCodeUG: writer.String("UG"); break;
            case CountryCodeUA: writer.String("UA"); break;
            case CountryCodeAE: writer.String("AE"); break;
            case CountryCodeGB: writer.String("GB"); break;
            case CountryCodeUS: writer.String("US"); break;
            case CountryCodeUM: writer.String("UM"); break;
            case CountryCodeUY: writer.String("UY"); break;
            case CountryCodeUZ: writer.String("UZ"); break;
            case CountryCodeVU: writer.String("VU"); break;
            case CountryCodeVE: writer.String("VE"); break;
            case CountryCodeVN: writer.String("VN"); break;
            case CountryCodeVG: writer.String("VG"); break;
            case CountryCodeVI: writer.String("VI"); break;
            case CountryCodeWF: writer.String("WF"); break;
            case CountryCodeEH: writer.String("EH"); break;
            case CountryCodeYE: writer.String("YE"); break;
            case CountryCodeZM: writer.String("ZM"); break;
            case CountryCodeZW: writer.String("ZW"); break;

            }
        }

        inline CountryCode readCountryCodeFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, CountryCode> _CountryCodeMap;
            if (_CountryCodeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CountryCodeMap["AF"] = CountryCodeAF;
                _CountryCodeMap["AX"] = CountryCodeAX;
                _CountryCodeMap["AL"] = CountryCodeAL;
                _CountryCodeMap["DZ"] = CountryCodeDZ;
                _CountryCodeMap["AS"] = CountryCodeAS;
                _CountryCodeMap["AD"] = CountryCodeAD;
                _CountryCodeMap["AO"] = CountryCodeAO;
                _CountryCodeMap["AI"] = CountryCodeAI;
                _CountryCodeMap["AQ"] = CountryCodeAQ;
                _CountryCodeMap["AG"] = CountryCodeAG;
                _CountryCodeMap["AR"] = CountryCodeAR;
                _CountryCodeMap["AM"] = CountryCodeAM;
                _CountryCodeMap["AW"] = CountryCodeAW;
                _CountryCodeMap["AU"] = CountryCodeAU;
                _CountryCodeMap["AT"] = CountryCodeAT;
                _CountryCodeMap["AZ"] = CountryCodeAZ;
                _CountryCodeMap["BS"] = CountryCodeBS;
                _CountryCodeMap["BH"] = CountryCodeBH;
                _CountryCodeMap["BD"] = CountryCodeBD;
                _CountryCodeMap["BB"] = CountryCodeBB;
                _CountryCodeMap["BY"] = CountryCodeBY;
                _CountryCodeMap["BE"] = CountryCodeBE;
                _CountryCodeMap["BZ"] = CountryCodeBZ;
                _CountryCodeMap["BJ"] = CountryCodeBJ;
                _CountryCodeMap["BM"] = CountryCodeBM;
                _CountryCodeMap["BT"] = CountryCodeBT;
                _CountryCodeMap["BO"] = CountryCodeBO;
                _CountryCodeMap["BQ"] = CountryCodeBQ;
                _CountryCodeMap["BA"] = CountryCodeBA;
                _CountryCodeMap["BW"] = CountryCodeBW;
                _CountryCodeMap["BV"] = CountryCodeBV;
                _CountryCodeMap["BR"] = CountryCodeBR;
                _CountryCodeMap["IO"] = CountryCodeIO;
                _CountryCodeMap["BN"] = CountryCodeBN;
                _CountryCodeMap["BG"] = CountryCodeBG;
                _CountryCodeMap["BF"] = CountryCodeBF;
                _CountryCodeMap["BI"] = CountryCodeBI;
                _CountryCodeMap["KH"] = CountryCodeKH;
                _CountryCodeMap["CM"] = CountryCodeCM;
                _CountryCodeMap["CA"] = CountryCodeCA;
                _CountryCodeMap["CV"] = CountryCodeCV;
                _CountryCodeMap["KY"] = CountryCodeKY;
                _CountryCodeMap["CF"] = CountryCodeCF;
                _CountryCodeMap["TD"] = CountryCodeTD;
                _CountryCodeMap["CL"] = CountryCodeCL;
                _CountryCodeMap["CN"] = CountryCodeCN;
                _CountryCodeMap["CX"] = CountryCodeCX;
                _CountryCodeMap["CC"] = CountryCodeCC;
                _CountryCodeMap["CO"] = CountryCodeCO;
                _CountryCodeMap["KM"] = CountryCodeKM;
                _CountryCodeMap["CG"] = CountryCodeCG;
                _CountryCodeMap["CD"] = CountryCodeCD;
                _CountryCodeMap["CK"] = CountryCodeCK;
                _CountryCodeMap["CR"] = CountryCodeCR;
                _CountryCodeMap["CI"] = CountryCodeCI;
                _CountryCodeMap["HR"] = CountryCodeHR;
                _CountryCodeMap["CU"] = CountryCodeCU;
                _CountryCodeMap["CW"] = CountryCodeCW;
                _CountryCodeMap["CY"] = CountryCodeCY;
                _CountryCodeMap["CZ"] = CountryCodeCZ;
                _CountryCodeMap["DK"] = CountryCodeDK;
                _CountryCodeMap["DJ"] = CountryCodeDJ;
                _CountryCodeMap["DM"] = CountryCodeDM;
                _CountryCodeMap["DO"] = CountryCodeDO;
                _CountryCodeMap["EC"] = CountryCodeEC;
                _CountryCodeMap["EG"] = CountryCodeEG;
                _CountryCodeMap["SV"] = CountryCodeSV;
                _CountryCodeMap["GQ"] = CountryCodeGQ;
                _CountryCodeMap["ER"] = CountryCodeER;
                _CountryCodeMap["EE"] = CountryCodeEE;
                _CountryCodeMap["ET"] = CountryCodeET;
                _CountryCodeMap["FK"] = CountryCodeFK;
                _CountryCodeMap["FO"] = CountryCodeFO;
                _CountryCodeMap["FJ"] = CountryCodeFJ;
                _CountryCodeMap["FI"] = CountryCodeFI;
                _CountryCodeMap["FR"] = CountryCodeFR;
                _CountryCodeMap["GF"] = CountryCodeGF;
                _CountryCodeMap["PF"] = CountryCodePF;
                _CountryCodeMap["TF"] = CountryCodeTF;
                _CountryCodeMap["GA"] = CountryCodeGA;
                _CountryCodeMap["GM"] = CountryCodeGM;
                _CountryCodeMap["GE"] = CountryCodeGE;
                _CountryCodeMap["DE"] = CountryCodeDE;
                _CountryCodeMap["GH"] = CountryCodeGH;
                _CountryCodeMap["GI"] = CountryCodeGI;
                _CountryCodeMap["GR"] = CountryCodeGR;
                _CountryCodeMap["GL"] = CountryCodeGL;
                _CountryCodeMap["GD"] = CountryCodeGD;
                _CountryCodeMap["GP"] = CountryCodeGP;
                _CountryCodeMap["GU"] = CountryCodeGU;
                _CountryCodeMap["GT"] = CountryCodeGT;
                _CountryCodeMap["GG"] = CountryCodeGG;
                _CountryCodeMap["GN"] = CountryCodeGN;
                _CountryCodeMap["GW"] = CountryCodeGW;
                _CountryCodeMap["GY"] = CountryCodeGY;
                _CountryCodeMap["HT"] = CountryCodeHT;
                _CountryCodeMap["HM"] = CountryCodeHM;
                _CountryCodeMap["VA"] = CountryCodeVA;
                _CountryCodeMap["HN"] = CountryCodeHN;
                _CountryCodeMap["HK"] = CountryCodeHK;
                _CountryCodeMap["HU"] = CountryCodeHU;
                _CountryCodeMap["IS"] = CountryCodeIS;
                _CountryCodeMap["IN"] = CountryCodeIN;
                _CountryCodeMap["ID"] = CountryCodeID;
                _CountryCodeMap["IR"] = CountryCodeIR;
                _CountryCodeMap["IQ"] = CountryCodeIQ;
                _CountryCodeMap["IE"] = CountryCodeIE;
                _CountryCodeMap["IM"] = CountryCodeIM;
                _CountryCodeMap["IL"] = CountryCodeIL;
                _CountryCodeMap["IT"] = CountryCodeIT;
                _CountryCodeMap["JM"] = CountryCodeJM;
                _CountryCodeMap["JP"] = CountryCodeJP;
                _CountryCodeMap["JE"] = CountryCodeJE;
                _CountryCodeMap["JO"] = CountryCodeJO;
                _CountryCodeMap["KZ"] = CountryCodeKZ;
                _CountryCodeMap["KE"] = CountryCodeKE;
                _CountryCodeMap["KI"] = CountryCodeKI;
                _CountryCodeMap["KP"] = CountryCodeKP;
                _CountryCodeMap["KR"] = CountryCodeKR;
                _CountryCodeMap["KW"] = CountryCodeKW;
                _CountryCodeMap["KG"] = CountryCodeKG;
                _CountryCodeMap["LA"] = CountryCodeLA;
                _CountryCodeMap["LV"] = CountryCodeLV;
                _CountryCodeMap["LB"] = CountryCodeLB;
                _CountryCodeMap["LS"] = CountryCodeLS;
                _CountryCodeMap["LR"] = CountryCodeLR;
                _CountryCodeMap["LY"] = CountryCodeLY;
                _CountryCodeMap["LI"] = CountryCodeLI;
                _CountryCodeMap["LT"] = CountryCodeLT;
                _CountryCodeMap["LU"] = CountryCodeLU;
                _CountryCodeMap["MO"] = CountryCodeMO;
                _CountryCodeMap["MK"] = CountryCodeMK;
                _CountryCodeMap["MG"] = CountryCodeMG;
                _CountryCodeMap["MW"] = CountryCodeMW;
                _CountryCodeMap["MY"] = CountryCodeMY;
                _CountryCodeMap["MV"] = CountryCodeMV;
                _CountryCodeMap["ML"] = CountryCodeML;
                _CountryCodeMap["MT"] = CountryCodeMT;
                _CountryCodeMap["MH"] = CountryCodeMH;
                _CountryCodeMap["MQ"] = CountryCodeMQ;
                _CountryCodeMap["MR"] = CountryCodeMR;
                _CountryCodeMap["MU"] = CountryCodeMU;
                _CountryCodeMap["YT"] = CountryCodeYT;
                _CountryCodeMap["MX"] = CountryCodeMX;
                _CountryCodeMap["FM"] = CountryCodeFM;
                _CountryCodeMap["MD"] = CountryCodeMD;
                _CountryCodeMap["MC"] = CountryCodeMC;
                _CountryCodeMap["MN"] = CountryCodeMN;
                _CountryCodeMap["ME"] = CountryCodeME;
                _CountryCodeMap["MS"] = CountryCodeMS;
                _CountryCodeMap["MA"] = CountryCodeMA;
                _CountryCodeMap["MZ"] = CountryCodeMZ;
                _CountryCodeMap["MM"] = CountryCodeMM;
                _CountryCodeMap["NA"] = CountryCodeNA;
                _CountryCodeMap["NR"] = CountryCodeNR;
                _CountryCodeMap["NP"] = CountryCodeNP;
                _CountryCodeMap["NL"] = CountryCodeNL;
                _CountryCodeMap["NC"] = CountryCodeNC;
                _CountryCodeMap["NZ"] = CountryCodeNZ;
                _CountryCodeMap["NI"] = CountryCodeNI;
                _CountryCodeMap["NE"] = CountryCodeNE;
                _CountryCodeMap["NG"] = CountryCodeNG;
                _CountryCodeMap["NU"] = CountryCodeNU;
                _CountryCodeMap["NF"] = CountryCodeNF;
                _CountryCodeMap["MP"] = CountryCodeMP;
                _CountryCodeMap["NO"] = CountryCodeNO;
                _CountryCodeMap["OM"] = CountryCodeOM;
                _CountryCodeMap["PK"] = CountryCodePK;
                _CountryCodeMap["PW"] = CountryCodePW;
                _CountryCodeMap["PS"] = CountryCodePS;
                _CountryCodeMap["PA"] = CountryCodePA;
                _CountryCodeMap["PG"] = CountryCodePG;
                _CountryCodeMap["PY"] = CountryCodePY;
                _CountryCodeMap["PE"] = CountryCodePE;
                _CountryCodeMap["PH"] = CountryCodePH;
                _CountryCodeMap["PN"] = CountryCodePN;
                _CountryCodeMap["PL"] = CountryCodePL;
                _CountryCodeMap["PT"] = CountryCodePT;
                _CountryCodeMap["PR"] = CountryCodePR;
                _CountryCodeMap["QA"] = CountryCodeQA;
                _CountryCodeMap["RE"] = CountryCodeRE;
                _CountryCodeMap["RO"] = CountryCodeRO;
                _CountryCodeMap["RU"] = CountryCodeRU;
                _CountryCodeMap["RW"] = CountryCodeRW;
                _CountryCodeMap["BL"] = CountryCodeBL;
                _CountryCodeMap["SH"] = CountryCodeSH;
                _CountryCodeMap["KN"] = CountryCodeKN;
                _CountryCodeMap["LC"] = CountryCodeLC;
                _CountryCodeMap["MF"] = CountryCodeMF;
                _CountryCodeMap["PM"] = CountryCodePM;
                _CountryCodeMap["VC"] = CountryCodeVC;
                _CountryCodeMap["WS"] = CountryCodeWS;
                _CountryCodeMap["SM"] = CountryCodeSM;
                _CountryCodeMap["ST"] = CountryCodeST;
                _CountryCodeMap["SA"] = CountryCodeSA;
                _CountryCodeMap["SN"] = CountryCodeSN;
                _CountryCodeMap["RS"] = CountryCodeRS;
                _CountryCodeMap["SC"] = CountryCodeSC;
                _CountryCodeMap["SL"] = CountryCodeSL;
                _CountryCodeMap["SG"] = CountryCodeSG;
                _CountryCodeMap["SX"] = CountryCodeSX;
                _CountryCodeMap["SK"] = CountryCodeSK;
                _CountryCodeMap["SI"] = CountryCodeSI;
                _CountryCodeMap["SB"] = CountryCodeSB;
                _CountryCodeMap["SO"] = CountryCodeSO;
                _CountryCodeMap["ZA"] = CountryCodeZA;
                _CountryCodeMap["GS"] = CountryCodeGS;
                _CountryCodeMap["SS"] = CountryCodeSS;
                _CountryCodeMap["ES"] = CountryCodeES;
                _CountryCodeMap["LK"] = CountryCodeLK;
                _CountryCodeMap["SD"] = CountryCodeSD;
                _CountryCodeMap["SR"] = CountryCodeSR;
                _CountryCodeMap["SJ"] = CountryCodeSJ;
                _CountryCodeMap["SZ"] = CountryCodeSZ;
                _CountryCodeMap["SE"] = CountryCodeSE;
                _CountryCodeMap["CH"] = CountryCodeCH;
                _CountryCodeMap["SY"] = CountryCodeSY;
                _CountryCodeMap["TW"] = CountryCodeTW;
                _CountryCodeMap["TJ"] = CountryCodeTJ;
                _CountryCodeMap["TZ"] = CountryCodeTZ;
                _CountryCodeMap["TH"] = CountryCodeTH;
                _CountryCodeMap["TL"] = CountryCodeTL;
                _CountryCodeMap["TG"] = CountryCodeTG;
                _CountryCodeMap["TK"] = CountryCodeTK;
                _CountryCodeMap["TO"] = CountryCodeTO;
                _CountryCodeMap["TT"] = CountryCodeTT;
                _CountryCodeMap["TN"] = CountryCodeTN;
                _CountryCodeMap["TR"] = CountryCodeTR;
                _CountryCodeMap["TM"] = CountryCodeTM;
                _CountryCodeMap["TC"] = CountryCodeTC;
                _CountryCodeMap["TV"] = CountryCodeTV;
                _CountryCodeMap["UG"] = CountryCodeUG;
                _CountryCodeMap["UA"] = CountryCodeUA;
                _CountryCodeMap["AE"] = CountryCodeAE;
                _CountryCodeMap["GB"] = CountryCodeGB;
                _CountryCodeMap["US"] = CountryCodeUS;
                _CountryCodeMap["UM"] = CountryCodeUM;
                _CountryCodeMap["UY"] = CountryCodeUY;
                _CountryCodeMap["UZ"] = CountryCodeUZ;
                _CountryCodeMap["VU"] = CountryCodeVU;
                _CountryCodeMap["VE"] = CountryCodeVE;
                _CountryCodeMap["VN"] = CountryCodeVN;
                _CountryCodeMap["VG"] = CountryCodeVG;
                _CountryCodeMap["VI"] = CountryCodeVI;
                _CountryCodeMap["WF"] = CountryCodeWF;
                _CountryCodeMap["EH"] = CountryCodeEH;
                _CountryCodeMap["YE"] = CountryCodeYE;
                _CountryCodeMap["ZM"] = CountryCodeZM;
                _CountryCodeMap["ZW"] = CountryCodeZW;

            }

            auto output = _CountryCodeMap.find(obj.GetString());
            if (output != _CountryCodeMap.end())
                return output->second;

            return CountryCodeAF; // Basically critical fail
        }

        struct CreateSharedGroupRequest : public PlayFabBaseModel
        {
            Aws::String SharedGroupId;

            CreateSharedGroupRequest() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            CreateSharedGroupRequest(const CreateSharedGroupRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            CreateSharedGroupRequest(const rapidjson::Value& obj) : CreateSharedGroupRequest()
            {
                readFromValue(obj);
            }

            ~CreateSharedGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct CreateSharedGroupResult : public PlayFabBaseModel
        {
            Aws::String SharedGroupId;

            CreateSharedGroupResult() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            CreateSharedGroupResult(const CreateSharedGroupResult& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            CreateSharedGroupResult(const rapidjson::Value& obj) : CreateSharedGroupResult()
            {
                readFromValue(obj);
            }

            ~CreateSharedGroupResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct DeleteCharacterFromUserRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            bool SaveCharacterInventory;

            DeleteCharacterFromUserRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                SaveCharacterInventory(false)
            {}

            DeleteCharacterFromUserRequest(const DeleteCharacterFromUserRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                SaveCharacterInventory(src.SaveCharacterInventory)
            {}

            DeleteCharacterFromUserRequest(const rapidjson::Value& obj) : DeleteCharacterFromUserRequest()
            {
                readFromValue(obj);
            }

            ~DeleteCharacterFromUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.String("SaveCharacterInventory"); writer.Bool(SaveCharacterInventory);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator SaveCharacterInventory_member = obj.FindMember("SaveCharacterInventory");
                if (SaveCharacterInventory_member != obj.MemberEnd() && !SaveCharacterInventory_member->value.IsNull()) SaveCharacterInventory = SaveCharacterInventory_member->value.GetBool();

                return true;
            }
        };

        struct DeleteCharacterFromUserResult : public PlayFabBaseModel
        {

            DeleteCharacterFromUserResult() :
                PlayFabBaseModel()
            {}

            DeleteCharacterFromUserResult(const DeleteCharacterFromUserResult& src) :
                PlayFabBaseModel()
            {}

            DeleteCharacterFromUserResult(const rapidjson::Value& obj) : DeleteCharacterFromUserResult()
            {
                readFromValue(obj);
            }

            ~DeleteCharacterFromUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct DeleteSharedGroupRequest : public PlayFabBaseModel
        {
            Aws::String SharedGroupId;

            DeleteSharedGroupRequest() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            DeleteSharedGroupRequest(const DeleteSharedGroupRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            DeleteSharedGroupRequest(const rapidjson::Value& obj) : DeleteSharedGroupRequest()
            {
                readFromValue(obj);
            }

            ~DeleteSharedGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct DeleteUsersRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> PlayFabIds;
            Aws::String TitleId;

            DeleteUsersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                TitleId()
            {}

            DeleteUsersRequest(const DeleteUsersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                TitleId(src.TitleId)
            {}

            DeleteUsersRequest(const rapidjson::Value& obj) : DeleteUsersRequest()
            {
                readFromValue(obj);
            }

            ~DeleteUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.String("TitleId"); writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct DeleteUsersResult : public PlayFabBaseModel
        {

            DeleteUsersResult() :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const DeleteUsersResult& src) :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const rapidjson::Value& obj) : DeleteUsersResult()
            {
                readFromValue(obj);
            }

            ~DeleteUsersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct DeregisterGameRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;

            DeregisterGameRequest() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            DeregisterGameRequest(const DeregisterGameRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            DeregisterGameRequest(const rapidjson::Value& obj) : DeregisterGameRequest()
            {
                readFromValue(obj);
            }

            ~DeregisterGameRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

                return true;
            }
        };

        struct DeregisterGameResponse : public PlayFabBaseModel
        {

            DeregisterGameResponse() :
                PlayFabBaseModel()
            {}

            DeregisterGameResponse(const DeregisterGameResponse& src) :
                PlayFabBaseModel()
            {}

            DeregisterGameResponse(const rapidjson::Value& obj) : DeregisterGameResponse()
            {
                readFromValue(obj);
            }

            ~DeregisterGameResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct EmptyResult : public PlayFabBaseModel
        {

            EmptyResult() :
                PlayFabBaseModel()
            {}

            EmptyResult(const EmptyResult& src) :
                PlayFabBaseModel()
            {}

            EmptyResult(const rapidjson::Value& obj) : EmptyResult()
            {
                readFromValue(obj);
            }

            ~EmptyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct EvaluateRandomResultTableRequest : public PlayFabBaseModel
        {
            Aws::String TableId;
            Aws::String CatalogVersion;

            EvaluateRandomResultTableRequest() :
                PlayFabBaseModel(),
                TableId(),
                CatalogVersion()
            {}

            EvaluateRandomResultTableRequest(const EvaluateRandomResultTableRequest& src) :
                PlayFabBaseModel(),
                TableId(src.TableId),
                CatalogVersion(src.CatalogVersion)
            {}

            EvaluateRandomResultTableRequest(const rapidjson::Value& obj) : EvaluateRandomResultTableRequest()
            {
                readFromValue(obj);
            }

            ~EvaluateRandomResultTableRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TableId"); writer.String(TableId.c_str());
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
                if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct EvaluateRandomResultTableResult : public PlayFabBaseModel
        {
            Aws::String ResultItemId;

            EvaluateRandomResultTableResult() :
                PlayFabBaseModel(),
                ResultItemId()
            {}

            EvaluateRandomResultTableResult(const EvaluateRandomResultTableResult& src) :
                PlayFabBaseModel(),
                ResultItemId(src.ResultItemId)
            {}

            EvaluateRandomResultTableResult(const rapidjson::Value& obj) : EvaluateRandomResultTableResult()
            {
                readFromValue(obj);
            }

            ~EvaluateRandomResultTableResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ResultItemId.length() > 0) { writer.String("ResultItemId"); writer.String(ResultItemId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ResultItemId_member = obj.FindMember("ResultItemId");
                if (ResultItemId_member != obj.MemberEnd() && !ResultItemId_member->value.IsNull()) ResultItemId = ResultItemId_member->value.GetString();

                return true;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
            Aws::String Level;
            Aws::String Message;
            MultitypeVar Data;

            LogStatement() :
                PlayFabBaseModel(),
                Level(),
                Message(),
                Data()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Level(src.Level),
                Message(src.Message),
                Data(src.Data)
            {}

            LogStatement(const rapidjson::Value& obj) : LogStatement()
            {
                readFromValue(obj);
            }

            ~LogStatement()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Level.length() > 0) { writer.String("Level"); writer.String(Level.c_str()); }
                if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
                if (Data.notNull()) { writer.String("Data"); Data.writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Level_member = obj.FindMember("Level");
                if (Level_member != obj.MemberEnd() && !Level_member->value.IsNull()) Level = Level_member->value.GetString();
                const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
                if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd() && !Data_member->value.IsNull()) Data = MultitypeVar(Data_member->value);

                return true;
            }
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
            Aws::String Error;
            Aws::String Message;
            Aws::String StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ScriptExecutionError(const rapidjson::Value& obj) : ScriptExecutionError()
            {
                readFromValue(obj);
            }

            ~ScriptExecutionError()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Error.length() > 0) { writer.String("Error"); writer.String(Error.c_str()); }
                if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
                if (StackTrace.length() > 0) { writer.String("StackTrace"); writer.String(StackTrace.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
                if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
                const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
                if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
                const Value::ConstMemberIterator StackTrace_member = obj.FindMember("StackTrace");
                if (StackTrace_member != obj.MemberEnd() && !StackTrace_member->value.IsNull()) StackTrace = StackTrace_member->value.GetString();

                return true;
            }
        };

        struct ExecuteCloudScriptResult : public PlayFabBaseModel
        {
            Aws::String FunctionName;
            Int32 Revision;
            MultitypeVar FunctionResult;
            OptionalBool FunctionResultTooLarge;
            std::list<LogStatement> Logs;
            OptionalBool LogsTooLarge;
            double ExecutionTimeSeconds;
            double ProcessorTimeSeconds;
            Uint32 MemoryConsumedBytes;
            Int32 APIRequestsIssued;
            Int32 HttpRequestsIssued;
            ScriptExecutionError* Error;

            ExecuteCloudScriptResult() :
                PlayFabBaseModel(),
                FunctionName(),
                Revision(0),
                FunctionResult(),
                FunctionResultTooLarge(),
                Logs(),
                LogsTooLarge(),
                ExecutionTimeSeconds(0),
                ProcessorTimeSeconds(0),
                MemoryConsumedBytes(0),
                APIRequestsIssued(0),
                HttpRequestsIssued(0),
                Error(nullptr)
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                Revision(src.Revision),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                APIRequestsIssued(src.APIRequestsIssued),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Error(src.Error ? new ScriptExecutionError(*src.Error) : nullptr)
            {}

            ExecuteCloudScriptResult(const rapidjson::Value& obj) : ExecuteCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptResult()
            {
                if (Error != nullptr) delete Error;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FunctionName.length() > 0) { writer.String("FunctionName"); writer.String(FunctionName.c_str()); }
                writer.String("Revision"); writer.Int(Revision);
                if (FunctionResult.notNull()) { writer.String("FunctionResult"); FunctionResult.writeJSON(writer); }
                if (FunctionResultTooLarge.notNull()) { writer.String("FunctionResultTooLarge"); writer.Bool(FunctionResultTooLarge); }
                if (!Logs.empty()) {
    writer.String("Logs");
    writer.StartArray();
    for (std::list<LogStatement>::iterator iter = Logs.begin(); iter != Logs.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (LogsTooLarge.notNull()) { writer.String("LogsTooLarge"); writer.Bool(LogsTooLarge); }
                writer.String("ExecutionTimeSeconds"); writer.Double(ExecutionTimeSeconds);
                writer.String("ProcessorTimeSeconds"); writer.Double(ProcessorTimeSeconds);
                writer.String("MemoryConsumedBytes"); writer.Uint(MemoryConsumedBytes);
                writer.String("APIRequestsIssued"); writer.Int(APIRequestsIssued);
                writer.String("HttpRequestsIssued"); writer.Int(HttpRequestsIssued);
                if (Error != nullptr) { writer.String("Error"); Error->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
                if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
                const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
                if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = MultitypeVar(FunctionResult_member->value);
                const Value::ConstMemberIterator FunctionResultTooLarge_member = obj.FindMember("FunctionResultTooLarge");
                if (FunctionResultTooLarge_member != obj.MemberEnd() && !FunctionResultTooLarge_member->value.IsNull()) FunctionResultTooLarge = FunctionResultTooLarge_member->value.GetBool();
                const Value::ConstMemberIterator Logs_member = obj.FindMember("Logs");
    if (Logs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Logs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Logs.push_back(LogStatement(memberList[i]));
        }
    }
                const Value::ConstMemberIterator LogsTooLarge_member = obj.FindMember("LogsTooLarge");
                if (LogsTooLarge_member != obj.MemberEnd() && !LogsTooLarge_member->value.IsNull()) LogsTooLarge = LogsTooLarge_member->value.GetBool();
                const Value::ConstMemberIterator ExecutionTimeSeconds_member = obj.FindMember("ExecutionTimeSeconds");
                if (ExecutionTimeSeconds_member != obj.MemberEnd() && !ExecutionTimeSeconds_member->value.IsNull()) ExecutionTimeSeconds = ExecutionTimeSeconds_member->value.GetDouble();
                const Value::ConstMemberIterator ProcessorTimeSeconds_member = obj.FindMember("ProcessorTimeSeconds");
                if (ProcessorTimeSeconds_member != obj.MemberEnd() && !ProcessorTimeSeconds_member->value.IsNull()) ProcessorTimeSeconds = ProcessorTimeSeconds_member->value.GetDouble();
                const Value::ConstMemberIterator MemoryConsumedBytes_member = obj.FindMember("MemoryConsumedBytes");
                if (MemoryConsumedBytes_member != obj.MemberEnd() && !MemoryConsumedBytes_member->value.IsNull()) MemoryConsumedBytes = MemoryConsumedBytes_member->value.GetUint();
                const Value::ConstMemberIterator APIRequestsIssued_member = obj.FindMember("APIRequestsIssued");
                if (APIRequestsIssued_member != obj.MemberEnd() && !APIRequestsIssued_member->value.IsNull()) APIRequestsIssued = APIRequestsIssued_member->value.GetInt();
                const Value::ConstMemberIterator HttpRequestsIssued_member = obj.FindMember("HttpRequestsIssued");
                if (HttpRequestsIssued_member != obj.MemberEnd() && !HttpRequestsIssued_member->value.IsNull()) HttpRequestsIssued = HttpRequestsIssued_member->value.GetInt();
                const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
                if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = new ScriptExecutionError(Error_member->value);

                return true;
            }
        };

        struct ExecuteCloudScriptServerRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String FunctionName;
            MultitypeVar FunctionParameter;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            OptionalInt32 SpecificRevision;
            OptionalBool GeneratePlayStreamEvent;

            ExecuteCloudScriptServerRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                FunctionName(),
                FunctionParameter(),
                RevisionSelection(),
                SpecificRevision(),
                GeneratePlayStreamEvent()
            {}

            ExecuteCloudScriptServerRequest(const ExecuteCloudScriptServerRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent)
            {}

            ExecuteCloudScriptServerRequest(const rapidjson::Value& obj) : ExecuteCloudScriptServerRequest()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptServerRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("FunctionName"); writer.String(FunctionName.c_str());
                if (FunctionParameter.notNull()) { writer.String("FunctionParameter"); FunctionParameter.writeJSON(writer); }
                if (RevisionSelection.notNull()) { writer.String("RevisionSelection"); writeCloudScriptRevisionOptionEnumJSON(RevisionSelection, writer); }
                if (SpecificRevision.notNull()) { writer.String("SpecificRevision"); writer.Int(SpecificRevision); }
                if (GeneratePlayStreamEvent.notNull()) { writer.String("GeneratePlayStreamEvent"); writer.Bool(GeneratePlayStreamEvent); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
                if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
                const Value::ConstMemberIterator FunctionParameter_member = obj.FindMember("FunctionParameter");
                if (FunctionParameter_member != obj.MemberEnd() && !FunctionParameter_member->value.IsNull()) FunctionParameter = MultitypeVar(FunctionParameter_member->value);
                const Value::ConstMemberIterator RevisionSelection_member = obj.FindMember("RevisionSelection");
                if (RevisionSelection_member != obj.MemberEnd() && !RevisionSelection_member->value.IsNull()) RevisionSelection = readCloudScriptRevisionOptionFromValue(RevisionSelection_member->value);
                const Value::ConstMemberIterator SpecificRevision_member = obj.FindMember("SpecificRevision");
                if (SpecificRevision_member != obj.MemberEnd() && !SpecificRevision_member->value.IsNull()) SpecificRevision = SpecificRevision_member->value.GetInt();
                const Value::ConstMemberIterator GeneratePlayStreamEvent_member = obj.FindMember("GeneratePlayStreamEvent");
                if (GeneratePlayStreamEvent_member != obj.MemberEnd() && !GeneratePlayStreamEvent_member->value.IsNull()) GeneratePlayStreamEvent = GeneratePlayStreamEvent_member->value.GetBool();

                return true;
            }
        };

        struct FacebookPlayFabIdPair : public PlayFabBaseModel
        {
            Aws::String FacebookId;
            Aws::String PlayFabId;

            FacebookPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookId(),
                PlayFabId()
            {}

            FacebookPlayFabIdPair(const FacebookPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                PlayFabId(src.PlayFabId)
            {}

            FacebookPlayFabIdPair(const rapidjson::Value& obj) : FacebookPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~FacebookPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FacebookId.length() > 0) { writer.String("FacebookId"); writer.String(FacebookId.c_str()); }
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
                if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct FriendInfo : public PlayFabBaseModel
        {
            Aws::String FriendPlayFabId;
            Aws::String Username;
            Aws::String TitleDisplayName;
            std::list<Aws::String> Tags;
            Aws::String CurrentMatchmakerLobbyId;
            UserFacebookInfo* FacebookInfo;
            UserSteamInfo* SteamInfo;
            UserGameCenterInfo* GameCenterInfo;

            FriendInfo() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                Username(),
                TitleDisplayName(),
                Tags(),
                CurrentMatchmakerLobbyId(),
                FacebookInfo(nullptr),
                SteamInfo(nullptr),
                GameCenterInfo(nullptr)
            {}

            FriendInfo(const FriendInfo& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                Username(src.Username),
                TitleDisplayName(src.TitleDisplayName),
                Tags(src.Tags),
                CurrentMatchmakerLobbyId(src.CurrentMatchmakerLobbyId),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : nullptr),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : nullptr),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : nullptr)
            {}

            FriendInfo(const rapidjson::Value& obj) : FriendInfo()
            {
                readFromValue(obj);
            }

            ~FriendInfo()
            {
                if (FacebookInfo != nullptr) delete FacebookInfo;
                if (SteamInfo != nullptr) delete SteamInfo;
                if (GameCenterInfo != nullptr) delete GameCenterInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FriendPlayFabId.length() > 0) { writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str()); }
                if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
                if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
                if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (CurrentMatchmakerLobbyId.length() > 0) { writer.String("CurrentMatchmakerLobbyId"); writer.String(CurrentMatchmakerLobbyId.c_str()); }
                if (FacebookInfo != nullptr) { writer.String("FacebookInfo"); FacebookInfo->writeJSON(writer); }
                if (SteamInfo != nullptr) { writer.String("SteamInfo"); SteamInfo->writeJSON(writer); }
                if (GameCenterInfo != nullptr) { writer.String("GameCenterInfo"); GameCenterInfo->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
                if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator CurrentMatchmakerLobbyId_member = obj.FindMember("CurrentMatchmakerLobbyId");
                if (CurrentMatchmakerLobbyId_member != obj.MemberEnd() && !CurrentMatchmakerLobbyId_member->value.IsNull()) CurrentMatchmakerLobbyId = CurrentMatchmakerLobbyId_member->value.GetString();
                const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
                if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
                const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
                if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
                const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
                if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);

                return true;
            }
        };

        enum GameInstanceState
        {
            GameInstanceStateOpen,
            GameInstanceStateClosed
        };

        inline void writeGameInstanceStateEnumJSON(GameInstanceState enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case GameInstanceStateOpen: writer.String("Open"); break;
            case GameInstanceStateClosed: writer.String("Closed"); break;

            }
        }

        inline GameInstanceState readGameInstanceStateFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, GameInstanceState> _GameInstanceStateMap;
            if (_GameInstanceStateMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _GameInstanceStateMap["Open"] = GameInstanceStateOpen;
                _GameInstanceStateMap["Closed"] = GameInstanceStateClosed;

            }

            auto output = _GameInstanceStateMap.find(obj.GetString());
            if (output != _GameInstanceStateMap.end())
                return output->second;

            return GameInstanceStateOpen; // Basically critical fail
        }

        struct GetActionGroupResult : public PlayFabBaseModel
        {
            Aws::String Name;
            Aws::String Id;

            GetActionGroupResult() :
                PlayFabBaseModel(),
                Name(),
                Id()
            {}

            GetActionGroupResult(const GetActionGroupResult& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Id(src.Id)
            {}

            GetActionGroupResult(const rapidjson::Value& obj) : GetActionGroupResult()
            {
                readFromValue(obj);
            }

            ~GetActionGroupResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Name"); writer.String(Name.c_str());
                if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();

                return true;
            }
        };

        struct GetAllActionGroupsRequest : public PlayFabBaseModel
        {

            GetAllActionGroupsRequest() :
                PlayFabBaseModel()
            {}

            GetAllActionGroupsRequest(const GetAllActionGroupsRequest& src) :
                PlayFabBaseModel()
            {}

            GetAllActionGroupsRequest(const rapidjson::Value& obj) : GetAllActionGroupsRequest()
            {
                readFromValue(obj);
            }

            ~GetAllActionGroupsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetAllActionGroupsResult : public PlayFabBaseModel
        {
            std::list<GetActionGroupResult> ActionGroups;

            GetAllActionGroupsResult() :
                PlayFabBaseModel(),
                ActionGroups()
            {}

            GetAllActionGroupsResult(const GetAllActionGroupsResult& src) :
                PlayFabBaseModel(),
                ActionGroups(src.ActionGroups)
            {}

            GetAllActionGroupsResult(const rapidjson::Value& obj) : GetAllActionGroupsResult()
            {
                readFromValue(obj);
            }

            ~GetAllActionGroupsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ActionGroups");
    writer.StartArray();
    for (std::list<GetActionGroupResult>::iterator iter = ActionGroups.begin(); iter != ActionGroups.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ActionGroups_member = obj.FindMember("ActionGroups");
    if (ActionGroups_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActionGroups_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActionGroups.push_back(GetActionGroupResult(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetAllSegmentsRequest : public PlayFabBaseModel
        {

            GetAllSegmentsRequest() :
                PlayFabBaseModel()
            {}

            GetAllSegmentsRequest(const GetAllSegmentsRequest& src) :
                PlayFabBaseModel()
            {}

            GetAllSegmentsRequest(const rapidjson::Value& obj) : GetAllSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetAllSegmentsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetSegmentResult : public PlayFabBaseModel
        {
            Aws::String Id;
            Aws::String Name;
            Aws::String ABTestParent;

            GetSegmentResult() :
                PlayFabBaseModel(),
                Id(),
                Name(),
                ABTestParent()
            {}

            GetSegmentResult(const GetSegmentResult& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name),
                ABTestParent(src.ABTestParent)
            {}

            GetSegmentResult(const rapidjson::Value& obj) : GetSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetSegmentResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Id"); writer.String(Id.c_str());
                if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
                if (ABTestParent.length() > 0) { writer.String("ABTestParent"); writer.String(ABTestParent.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator ABTestParent_member = obj.FindMember("ABTestParent");
                if (ABTestParent_member != obj.MemberEnd() && !ABTestParent_member->value.IsNull()) ABTestParent = ABTestParent_member->value.GetString();

                return true;
            }
        };

        struct GetAllSegmentsResult : public PlayFabBaseModel
        {
            std::list<GetSegmentResult> Segments;

            GetAllSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetAllSegmentsResult(const GetAllSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetAllSegmentsResult(const rapidjson::Value& obj) : GetAllSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetAllSegmentsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Segments.empty()) {
    writer.String("Segments");
    writer.StartArray();
    for (std::list<GetSegmentResult>::iterator iter = Segments.begin(); iter != Segments.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Segments_member = obj.FindMember("Segments");
    if (Segments_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Segments_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Segments.push_back(GetSegmentResult(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetCatalogItemsRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;

            GetCatalogItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion()
            {}

            GetCatalogItemsRequest(const GetCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion)
            {}

            GetCatalogItemsRequest(const rapidjson::Value& obj) : GetCatalogItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct GetCatalogItemsResult : public PlayFabBaseModel
        {
            std::list<CatalogItem> Catalog;

            GetCatalogItemsResult() :
                PlayFabBaseModel(),
                Catalog()
            {}

            GetCatalogItemsResult(const GetCatalogItemsResult& src) :
                PlayFabBaseModel(),
                Catalog(src.Catalog)
            {}

            GetCatalogItemsResult(const rapidjson::Value& obj) : GetCatalogItemsResult()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Catalog.empty()) {
    writer.String("Catalog");
    writer.StartArray();
    for (std::list<CatalogItem>::iterator iter = Catalog.begin(); iter != Catalog.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Catalog_member = obj.FindMember("Catalog");
    if (Catalog_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Catalog_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Catalog.push_back(CatalogItem(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetCharacterDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            std::list<Aws::String> Keys;
            OptionalUint32 IfChangedFromDataVersion;

            GetCharacterDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Keys(),
                IfChangedFromDataVersion()
            {}

            GetCharacterDataRequest(const GetCharacterDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Keys(src.Keys),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion)
            {}

            GetCharacterDataRequest(const rapidjson::Value& obj) : GetCharacterDataRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Uint(IfChangedFromDataVersion); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
                if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();

                return true;
            }
        };

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        inline void writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case UserDataPermissionPrivate: writer.String("Private"); break;
            case UserDataPermissionPublic: writer.String("Public"); break;

            }
        }

        inline UserDataPermission readUserDataPermissionFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, UserDataPermission> _UserDataPermissionMap;
            if (_UserDataPermissionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _UserDataPermissionMap["Private"] = UserDataPermissionPrivate;
                _UserDataPermissionMap["Public"] = UserDataPermissionPublic;

            }

            auto output = _UserDataPermissionMap.find(obj.GetString());
            if (output != _UserDataPermissionMap.end())
                return output->second;

            return UserDataPermissionPrivate; // Basically critical fail
        }

        struct UserDataRecord : public PlayFabBaseModel
        {
            Aws::String Value;
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;

            UserDataRecord() :
                PlayFabBaseModel(),
                Value(),
                LastUpdated(0),
                Permission()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                Value(src.Value),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission)
            {}

            UserDataRecord(const rapidjson::Value& obj) : UserDataRecord()
            {
                readFromValue(obj);
            }

            ~UserDataRecord()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
                writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
                if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
                const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
                if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct GetCharacterDataResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Uint32 DataVersion;
            std::map<Aws::String, UserDataRecord> Data;
            Aws::String CharacterId;

            GetCharacterDataResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                DataVersion(0),
                Data(),
                CharacterId()
            {}

            GetCharacterDataResult(const GetCharacterDataResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DataVersion(src.DataVersion),
                Data(src.Data),
                CharacterId(src.CharacterId)
            {}

            GetCharacterDataResult(const rapidjson::Value& obj) : GetCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                writer.String("DataVersion"); writer.Uint(DataVersion);
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct GetCharacterInventoryRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String CatalogVersion;

            GetCharacterInventoryRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                CatalogVersion()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                CatalogVersion(src.CatalogVersion)
            {}

            GetCharacterInventoryRequest(const rapidjson::Value& obj) : GetCharacterInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
            Int32 SecondsToRecharge;
            time_t RechargeTime;
            Int32 RechargeMax;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                SecondsToRecharge(0),
                RechargeTime(0),
                RechargeMax(0)
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                SecondsToRecharge(src.SecondsToRecharge),
                RechargeTime(src.RechargeTime),
                RechargeMax(src.RechargeMax)
            {}

            VirtualCurrencyRechargeTime(const rapidjson::Value& obj) : VirtualCurrencyRechargeTime()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyRechargeTime()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SecondsToRecharge"); writer.Int(SecondsToRecharge);
                writer.String("RechargeTime"); writeDatetime(RechargeTime, writer);
                writer.String("RechargeMax"); writer.Int(RechargeMax);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SecondsToRecharge_member = obj.FindMember("SecondsToRecharge");
                if (SecondsToRecharge_member != obj.MemberEnd() && !SecondsToRecharge_member->value.IsNull()) SecondsToRecharge = SecondsToRecharge_member->value.GetInt();
                const Value::ConstMemberIterator RechargeTime_member = obj.FindMember("RechargeTime");
                if (RechargeTime_member != obj.MemberEnd() && !RechargeTime_member->value.IsNull()) RechargeTime = readDatetime(RechargeTime_member->value);
                const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
                if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();

                return true;
            }
        };

        struct GetCharacterInventoryResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            std::list<ItemInstance> Inventory;
            std::map<Aws::String, Int32> VirtualCurrency;
            std::map<Aws::String, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetCharacterInventoryResult(const rapidjson::Value& obj) : GetCharacterInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                if (!Inventory.empty()) {
    writer.String("Inventory");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!VirtualCurrency.empty()) {
    writer.String("VirtualCurrency");
    writer.StartObject();
    for (std::map<Aws::String, Int32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
                if (!VirtualCurrencyRechargeTimes.empty()) {
    writer.String("VirtualCurrencyRechargeTimes");
    writer.StartObject();
    for (std::map<Aws::String, VirtualCurrencyRechargeTime>::iterator iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }
                const Value::ConstMemberIterator VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
    if (VirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != VirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
        }
    }

                return true;
            }
        };

        struct GetCharacterLeaderboardRequest : public PlayFabBaseModel
        {
            Aws::String CharacterId;
            Aws::String CharacterType;
            Aws::String StatisticName;
            Int32 StartPosition;
            Int32 MaxResultsCount;

            GetCharacterLeaderboardRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterType(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount(0)
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetCharacterLeaderboardRequest(const rapidjson::Value& obj) : GetCharacterLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterLeaderboardRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                writer.String("StartPosition"); writer.Int(StartPosition);
                writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

                return true;
            }
        };

        struct GetCharacterLeaderboardResult : public PlayFabBaseModel
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetCharacterLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetCharacterLeaderboardResult(const GetCharacterLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetCharacterLeaderboardResult(const rapidjson::Value& obj) : GetCharacterLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterLeaderboardResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<CharacterLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetCharacterStatisticsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;

            GetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId()
            {}

            GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId)
            {}

            GetCharacterStatisticsRequest(const rapidjson::Value& obj) : GetCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct GetCharacterStatisticsResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            std::map<Aws::String, Int32> CharacterStatistics;

            GetCharacterStatisticsResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                CharacterStatistics()
            {}

            GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics)
            {}

            GetCharacterStatisticsResult(const rapidjson::Value& obj) : GetCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                if (!CharacterStatistics.empty()) {
    writer.String("CharacterStatistics");
    writer.StartObject();
    for (std::map<Aws::String, Int32>::iterator iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
    if (CharacterStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
            CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }

                return true;
            }
        };

        struct GetContentDownloadUrlRequest : public PlayFabBaseModel
        {
            Aws::String Key;
            Aws::String HttpMethod;
            OptionalBool ThruCDN;

            GetContentDownloadUrlRequest() :
                PlayFabBaseModel(),
                Key(),
                HttpMethod(),
                ThruCDN()
            {}

            GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                HttpMethod(src.HttpMethod),
                ThruCDN(src.ThruCDN)
            {}

            GetContentDownloadUrlRequest(const rapidjson::Value& obj) : GetContentDownloadUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetContentDownloadUrlRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key"); writer.String(Key.c_str());
                if (HttpMethod.length() > 0) { writer.String("HttpMethod"); writer.String(HttpMethod.c_str()); }
                if (ThruCDN.notNull()) { writer.String("ThruCDN"); writer.Bool(ThruCDN); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator HttpMethod_member = obj.FindMember("HttpMethod");
                if (HttpMethod_member != obj.MemberEnd() && !HttpMethod_member->value.IsNull()) HttpMethod = HttpMethod_member->value.GetString();
                const Value::ConstMemberIterator ThruCDN_member = obj.FindMember("ThruCDN");
                if (ThruCDN_member != obj.MemberEnd() && !ThruCDN_member->value.IsNull()) ThruCDN = ThruCDN_member->value.GetBool();

                return true;
            }
        };

        struct GetContentDownloadUrlResult : public PlayFabBaseModel
        {
            Aws::String URL;

            GetContentDownloadUrlResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetContentDownloadUrlResult(const GetContentDownloadUrlResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetContentDownloadUrlResult(const rapidjson::Value& obj) : GetContentDownloadUrlResult()
            {
                readFromValue(obj);
            }

            ~GetContentDownloadUrlResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator URL_member = obj.FindMember("URL");
                if (URL_member != obj.MemberEnd() && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

                return true;
            }
        };

        struct PlayerProfileViewConstraints : public PlayFabBaseModel
        {
            bool ShowDisplayName;
            bool ShowCreated;
            bool ShowOrigination;
            bool ShowLastLogin;
            bool ShowBannedUntil;
            bool ShowStatistics;
            bool ShowCampaignAttributions;
            bool ShowPushNotificationRegistrations;
            bool ShowLinkedAccounts;
            bool ShowTotalValueToDateInUsd;
            bool ShowValuesToDate;
            bool ShowTags;
            bool ShowLocations;
            bool ShowAvatarUrl;

            PlayerProfileViewConstraints() :
                PlayFabBaseModel(),
                ShowDisplayName(false),
                ShowCreated(false),
                ShowOrigination(false),
                ShowLastLogin(false),
                ShowBannedUntil(false),
                ShowStatistics(false),
                ShowCampaignAttributions(false),
                ShowPushNotificationRegistrations(false),
                ShowLinkedAccounts(false),
                ShowTotalValueToDateInUsd(false),
                ShowValuesToDate(false),
                ShowTags(false),
                ShowLocations(false),
                ShowAvatarUrl(false)
            {}

            PlayerProfileViewConstraints(const PlayerProfileViewConstraints& src) :
                PlayFabBaseModel(),
                ShowDisplayName(src.ShowDisplayName),
                ShowCreated(src.ShowCreated),
                ShowOrigination(src.ShowOrigination),
                ShowLastLogin(src.ShowLastLogin),
                ShowBannedUntil(src.ShowBannedUntil),
                ShowStatistics(src.ShowStatistics),
                ShowCampaignAttributions(src.ShowCampaignAttributions),
                ShowPushNotificationRegistrations(src.ShowPushNotificationRegistrations),
                ShowLinkedAccounts(src.ShowLinkedAccounts),
                ShowTotalValueToDateInUsd(src.ShowTotalValueToDateInUsd),
                ShowValuesToDate(src.ShowValuesToDate),
                ShowTags(src.ShowTags),
                ShowLocations(src.ShowLocations),
                ShowAvatarUrl(src.ShowAvatarUrl)
            {}

            PlayerProfileViewConstraints(const rapidjson::Value& obj) : PlayerProfileViewConstraints()
            {
                readFromValue(obj);
            }

            ~PlayerProfileViewConstraints()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ShowDisplayName"); writer.Bool(ShowDisplayName);
                writer.String("ShowCreated"); writer.Bool(ShowCreated);
                writer.String("ShowOrigination"); writer.Bool(ShowOrigination);
                writer.String("ShowLastLogin"); writer.Bool(ShowLastLogin);
                writer.String("ShowBannedUntil"); writer.Bool(ShowBannedUntil);
                writer.String("ShowStatistics"); writer.Bool(ShowStatistics);
                writer.String("ShowCampaignAttributions"); writer.Bool(ShowCampaignAttributions);
                writer.String("ShowPushNotificationRegistrations"); writer.Bool(ShowPushNotificationRegistrations);
                writer.String("ShowLinkedAccounts"); writer.Bool(ShowLinkedAccounts);
                writer.String("ShowTotalValueToDateInUsd"); writer.Bool(ShowTotalValueToDateInUsd);
                writer.String("ShowValuesToDate"); writer.Bool(ShowValuesToDate);
                writer.String("ShowTags"); writer.Bool(ShowTags);
                writer.String("ShowLocations"); writer.Bool(ShowLocations);
                writer.String("ShowAvatarUrl"); writer.Bool(ShowAvatarUrl);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ShowDisplayName_member = obj.FindMember("ShowDisplayName");
                if (ShowDisplayName_member != obj.MemberEnd() && !ShowDisplayName_member->value.IsNull()) ShowDisplayName = ShowDisplayName_member->value.GetBool();
                const Value::ConstMemberIterator ShowCreated_member = obj.FindMember("ShowCreated");
                if (ShowCreated_member != obj.MemberEnd() && !ShowCreated_member->value.IsNull()) ShowCreated = ShowCreated_member->value.GetBool();
                const Value::ConstMemberIterator ShowOrigination_member = obj.FindMember("ShowOrigination");
                if (ShowOrigination_member != obj.MemberEnd() && !ShowOrigination_member->value.IsNull()) ShowOrigination = ShowOrigination_member->value.GetBool();
                const Value::ConstMemberIterator ShowLastLogin_member = obj.FindMember("ShowLastLogin");
                if (ShowLastLogin_member != obj.MemberEnd() && !ShowLastLogin_member->value.IsNull()) ShowLastLogin = ShowLastLogin_member->value.GetBool();
                const Value::ConstMemberIterator ShowBannedUntil_member = obj.FindMember("ShowBannedUntil");
                if (ShowBannedUntil_member != obj.MemberEnd() && !ShowBannedUntil_member->value.IsNull()) ShowBannedUntil = ShowBannedUntil_member->value.GetBool();
                const Value::ConstMemberIterator ShowStatistics_member = obj.FindMember("ShowStatistics");
                if (ShowStatistics_member != obj.MemberEnd() && !ShowStatistics_member->value.IsNull()) ShowStatistics = ShowStatistics_member->value.GetBool();
                const Value::ConstMemberIterator ShowCampaignAttributions_member = obj.FindMember("ShowCampaignAttributions");
                if (ShowCampaignAttributions_member != obj.MemberEnd() && !ShowCampaignAttributions_member->value.IsNull()) ShowCampaignAttributions = ShowCampaignAttributions_member->value.GetBool();
                const Value::ConstMemberIterator ShowPushNotificationRegistrations_member = obj.FindMember("ShowPushNotificationRegistrations");
                if (ShowPushNotificationRegistrations_member != obj.MemberEnd() && !ShowPushNotificationRegistrations_member->value.IsNull()) ShowPushNotificationRegistrations = ShowPushNotificationRegistrations_member->value.GetBool();
                const Value::ConstMemberIterator ShowLinkedAccounts_member = obj.FindMember("ShowLinkedAccounts");
                if (ShowLinkedAccounts_member != obj.MemberEnd() && !ShowLinkedAccounts_member->value.IsNull()) ShowLinkedAccounts = ShowLinkedAccounts_member->value.GetBool();
                const Value::ConstMemberIterator ShowTotalValueToDateInUsd_member = obj.FindMember("ShowTotalValueToDateInUsd");
                if (ShowTotalValueToDateInUsd_member != obj.MemberEnd() && !ShowTotalValueToDateInUsd_member->value.IsNull()) ShowTotalValueToDateInUsd = ShowTotalValueToDateInUsd_member->value.GetBool();
                const Value::ConstMemberIterator ShowValuesToDate_member = obj.FindMember("ShowValuesToDate");
                if (ShowValuesToDate_member != obj.MemberEnd() && !ShowValuesToDate_member->value.IsNull()) ShowValuesToDate = ShowValuesToDate_member->value.GetBool();
                const Value::ConstMemberIterator ShowTags_member = obj.FindMember("ShowTags");
                if (ShowTags_member != obj.MemberEnd() && !ShowTags_member->value.IsNull()) ShowTags = ShowTags_member->value.GetBool();
                const Value::ConstMemberIterator ShowLocations_member = obj.FindMember("ShowLocations");
                if (ShowLocations_member != obj.MemberEnd() && !ShowLocations_member->value.IsNull()) ShowLocations = ShowLocations_member->value.GetBool();
                const Value::ConstMemberIterator ShowAvatarUrl_member = obj.FindMember("ShowAvatarUrl");
                if (ShowAvatarUrl_member != obj.MemberEnd() && !ShowAvatarUrl_member->value.IsNull()) ShowAvatarUrl = ShowAvatarUrl_member->value.GetBool();

                return true;
            }
        };

        struct GetFriendLeaderboardRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String StatisticName;
            Int32 StartPosition;
            Int32 MaxResultsCount;
            OptionalBool IncludeSteamFriends;
            OptionalBool IncludeFacebookFriends;
            OptionalInt32 Version;
            OptionalBool UseSpecificVersion;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetFriendLeaderboardRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount(0),
                IncludeSteamFriends(),
                IncludeFacebookFriends(),
                Version(),
                UseSpecificVersion(),
                ProfileConstraints(nullptr)
            {}

            GetFriendLeaderboardRequest(const GetFriendLeaderboardRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount),
                IncludeSteamFriends(src.IncludeSteamFriends),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                Version(src.Version),
                UseSpecificVersion(src.UseSpecificVersion),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetFriendLeaderboardRequest(const rapidjson::Value& obj) : GetFriendLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                writer.String("StartPosition"); writer.Int(StartPosition);
                writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
                if (IncludeSteamFriends.notNull()) { writer.String("IncludeSteamFriends"); writer.Bool(IncludeSteamFriends); }
                if (IncludeFacebookFriends.notNull()) { writer.String("IncludeFacebookFriends"); writer.Bool(IncludeFacebookFriends); }
                if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
                if (UseSpecificVersion.notNull()) { writer.String("UseSpecificVersion"); writer.Bool(UseSpecificVersion); }
                if (ProfileConstraints != nullptr) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
                if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
                const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
                if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator UseSpecificVersion_member = obj.FindMember("UseSpecificVersion");
                if (UseSpecificVersion_member != obj.MemberEnd() && !UseSpecificVersion_member->value.IsNull()) UseSpecificVersion = UseSpecificVersion_member->value.GetBool();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetFriendsListRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            OptionalBool IncludeSteamFriends;
            OptionalBool IncludeFacebookFriends;

            GetFriendsListRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                IncludeSteamFriends(),
                IncludeFacebookFriends()
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                IncludeSteamFriends(src.IncludeSteamFriends),
                IncludeFacebookFriends(src.IncludeFacebookFriends)
            {}

            GetFriendsListRequest(const rapidjson::Value& obj) : GetFriendsListRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendsListRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (IncludeSteamFriends.notNull()) { writer.String("IncludeSteamFriends"); writer.Bool(IncludeSteamFriends); }
                if (IncludeFacebookFriends.notNull()) { writer.String("IncludeFacebookFriends"); writer.Bool(IncludeFacebookFriends); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
                if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
                const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
                if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();

                return true;
            }
        };

        struct GetFriendsListResult : public PlayFabBaseModel
        {
            std::list<FriendInfo> Friends;

            GetFriendsListResult() :
                PlayFabBaseModel(),
                Friends()
            {}

            GetFriendsListResult(const GetFriendsListResult& src) :
                PlayFabBaseModel(),
                Friends(src.Friends)
            {}

            GetFriendsListResult(const rapidjson::Value& obj) : GetFriendsListResult()
            {
                readFromValue(obj);
            }

            ~GetFriendsListResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Friends.empty()) {
    writer.String("Friends");
    writer.StartArray();
    for (std::list<FriendInfo>::iterator iter = Friends.begin(); iter != Friends.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Friends_member = obj.FindMember("Friends");
    if (Friends_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Friends_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Friends.push_back(FriendInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetLeaderboardAroundCharacterRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String CharacterType;
            Int32 MaxResultsCount;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                PlayFabId(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(0)
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetLeaderboardAroundCharacterRequest(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCharacterRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
                writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

                return true;
            }
        };

        struct GetLeaderboardAroundCharacterResult : public PlayFabBaseModel
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetLeaderboardAroundCharacterResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardAroundCharacterResult(const GetLeaderboardAroundCharacterResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardAroundCharacterResult(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<CharacterLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetLeaderboardAroundUserRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Aws::String PlayFabId;
            Int32 MaxResultsCount;
            PlayerProfileViewConstraints* ProfileConstraints;
            OptionalInt32 Version;
            OptionalBool UseSpecificVersion;

            GetLeaderboardAroundUserRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                PlayFabId(),
                MaxResultsCount(0),
                ProfileConstraints(nullptr),
                Version(),
                UseSpecificVersion()
            {}

            GetLeaderboardAroundUserRequest(const GetLeaderboardAroundUserRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                PlayFabId(src.PlayFabId),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr),
                Version(src.Version),
                UseSpecificVersion(src.UseSpecificVersion)
            {}

            GetLeaderboardAroundUserRequest(const rapidjson::Value& obj) : GetLeaderboardAroundUserRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundUserRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
                if (ProfileConstraints != nullptr) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
                if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
                if (UseSpecificVersion.notNull()) { writer.String("UseSpecificVersion"); writer.Bool(UseSpecificVersion); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator UseSpecificVersion_member = obj.FindMember("UseSpecificVersion");
                if (UseSpecificVersion_member != obj.MemberEnd() && !UseSpecificVersion_member->value.IsNull()) UseSpecificVersion = UseSpecificVersion_member->value.GetBool();

                return true;
            }
        };

        enum LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello
        };

        inline void writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case LoginIdentityProviderUnknown: writer.String("Unknown"); break;
            case LoginIdentityProviderPlayFab: writer.String("PlayFab"); break;
            case LoginIdentityProviderCustom: writer.String("Custom"); break;
            case LoginIdentityProviderGameCenter: writer.String("GameCenter"); break;
            case LoginIdentityProviderGooglePlay: writer.String("GooglePlay"); break;
            case LoginIdentityProviderSteam: writer.String("Steam"); break;
            case LoginIdentityProviderXBoxLive: writer.String("XBoxLive"); break;
            case LoginIdentityProviderPSN: writer.String("PSN"); break;
            case LoginIdentityProviderKongregate: writer.String("Kongregate"); break;
            case LoginIdentityProviderFacebook: writer.String("Facebook"); break;
            case LoginIdentityProviderIOSDevice: writer.String("IOSDevice"); break;
            case LoginIdentityProviderAndroidDevice: writer.String("AndroidDevice"); break;
            case LoginIdentityProviderTwitch: writer.String("Twitch"); break;
            case LoginIdentityProviderWindowsHello: writer.String("WindowsHello"); break;

            }
        }

        inline LoginIdentityProvider readLoginIdentityProviderFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, LoginIdentityProvider> _LoginIdentityProviderMap;
            if (_LoginIdentityProviderMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _LoginIdentityProviderMap["Unknown"] = LoginIdentityProviderUnknown;
                _LoginIdentityProviderMap["PlayFab"] = LoginIdentityProviderPlayFab;
                _LoginIdentityProviderMap["Custom"] = LoginIdentityProviderCustom;
                _LoginIdentityProviderMap["GameCenter"] = LoginIdentityProviderGameCenter;
                _LoginIdentityProviderMap["GooglePlay"] = LoginIdentityProviderGooglePlay;
                _LoginIdentityProviderMap["Steam"] = LoginIdentityProviderSteam;
                _LoginIdentityProviderMap["XBoxLive"] = LoginIdentityProviderXBoxLive;
                _LoginIdentityProviderMap["PSN"] = LoginIdentityProviderPSN;
                _LoginIdentityProviderMap["Kongregate"] = LoginIdentityProviderKongregate;
                _LoginIdentityProviderMap["Facebook"] = LoginIdentityProviderFacebook;
                _LoginIdentityProviderMap["IOSDevice"] = LoginIdentityProviderIOSDevice;
                _LoginIdentityProviderMap["AndroidDevice"] = LoginIdentityProviderAndroidDevice;
                _LoginIdentityProviderMap["Twitch"] = LoginIdentityProviderTwitch;
                _LoginIdentityProviderMap["WindowsHello"] = LoginIdentityProviderWindowsHello;

            }

            auto output = _LoginIdentityProviderMap.find(obj.GetString());
            if (output != _LoginIdentityProviderMap.end())
                return output->second;

            return LoginIdentityProviderUnknown; // Basically critical fail
        }

        struct LocationModel : public PlayFabBaseModel
        {
            Boxed<ContinentCode> pfContinentCode;
            Boxed<CountryCode> pfCountryCode;
            Aws::String City;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            LocationModel() :
                PlayFabBaseModel(),
                pfContinentCode(),
                pfCountryCode(),
                City(),
                Latitude(),
                Longitude()
            {}

            LocationModel(const LocationModel& src) :
                PlayFabBaseModel(),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                City(src.City),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            LocationModel(const rapidjson::Value& obj) : LocationModel()
            {
                readFromValue(obj);
            }

            ~LocationModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (pfContinentCode.notNull()) { writer.String("ContinentCode"); writeContinentCodeEnumJSON(pfContinentCode, writer); }
                if (pfCountryCode.notNull()) { writer.String("CountryCode"); writeCountryCodeEnumJSON(pfCountryCode, writer); }
                if (City.length() > 0) { writer.String("City"); writer.String(City.c_str()); }
                if (Latitude.notNull()) { writer.String("Latitude"); writer.Double(Latitude); }
                if (Longitude.notNull()) { writer.String("Longitude"); writer.Double(Longitude); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ContinentCode_member = obj.FindMember("ContinentCode");
                if (ContinentCode_member != obj.MemberEnd() && !ContinentCode_member->value.IsNull()) pfContinentCode = readContinentCodeFromValue(ContinentCode_member->value);
                const Value::ConstMemberIterator CountryCode_member = obj.FindMember("CountryCode");
                if (CountryCode_member != obj.MemberEnd() && !CountryCode_member->value.IsNull()) pfCountryCode = readCountryCodeFromValue(CountryCode_member->value);
                const Value::ConstMemberIterator City_member = obj.FindMember("City");
                if (City_member != obj.MemberEnd() && !City_member->value.IsNull()) City = City_member->value.GetString();
                const Value::ConstMemberIterator Latitude_member = obj.FindMember("Latitude");
                if (Latitude_member != obj.MemberEnd() && !Latitude_member->value.IsNull()) Latitude = Latitude_member->value.GetDouble();
                const Value::ConstMemberIterator Longitude_member = obj.FindMember("Longitude");
                if (Longitude_member != obj.MemberEnd() && !Longitude_member->value.IsNull()) Longitude = Longitude_member->value.GetDouble();

                return true;
            }
        };

        struct TagModel : public PlayFabBaseModel
        {
            Aws::String TagValue;

            TagModel() :
                PlayFabBaseModel(),
                TagValue()
            {}

            TagModel(const TagModel& src) :
                PlayFabBaseModel(),
                TagValue(src.TagValue)
            {}

            TagModel(const rapidjson::Value& obj) : TagModel()
            {
                readFromValue(obj);
            }

            ~TagModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TagValue.length() > 0) { writer.String("TagValue"); writer.String(TagValue.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TagValue_member = obj.FindMember("TagValue");
                if (TagValue_member != obj.MemberEnd() && !TagValue_member->value.IsNull()) TagValue = TagValue_member->value.GetString();

                return true;
            }
        };

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        inline void writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case PushNotificationPlatformApplePushNotificationService: writer.String("ApplePushNotificationService"); break;
            case PushNotificationPlatformGoogleCloudMessaging: writer.String("GoogleCloudMessaging"); break;

            }
        }

        inline PushNotificationPlatform readPushNotificationPlatformFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, PushNotificationPlatform> _PushNotificationPlatformMap;
            if (_PushNotificationPlatformMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _PushNotificationPlatformMap["ApplePushNotificationService"] = PushNotificationPlatformApplePushNotificationService;
                _PushNotificationPlatformMap["GoogleCloudMessaging"] = PushNotificationPlatformGoogleCloudMessaging;

            }

            auto output = _PushNotificationPlatformMap.find(obj.GetString());
            if (output != _PushNotificationPlatformMap.end())
                return output->second;

            return PushNotificationPlatformApplePushNotificationService; // Basically critical fail
        }

        struct PushNotificationRegistrationModel : public PlayFabBaseModel
        {
            Boxed<PushNotificationPlatform> Platform;
            Aws::String NotificationEndpointARN;

            PushNotificationRegistrationModel() :
                PlayFabBaseModel(),
                Platform(),
                NotificationEndpointARN()
            {}

            PushNotificationRegistrationModel(const PushNotificationRegistrationModel& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                NotificationEndpointARN(src.NotificationEndpointARN)
            {}

            PushNotificationRegistrationModel(const rapidjson::Value& obj) : PushNotificationRegistrationModel()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistrationModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.notNull()) { writer.String("Platform"); writePushNotificationPlatformEnumJSON(Platform, writer); }
                if (NotificationEndpointARN.length() > 0) { writer.String("NotificationEndpointARN"); writer.String(NotificationEndpointARN.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushNotificationPlatformFromValue(Platform_member->value);
                const Value::ConstMemberIterator NotificationEndpointARN_member = obj.FindMember("NotificationEndpointARN");
                if (NotificationEndpointARN_member != obj.MemberEnd() && !NotificationEndpointARN_member->value.IsNull()) NotificationEndpointARN = NotificationEndpointARN_member->value.GetString();

                return true;
            }
        };

        struct LinkedPlatformAccountModel : public PlayFabBaseModel
        {
            Boxed<LoginIdentityProvider> Platform;
            Aws::String PlatformUserId;
            Aws::String Username;
            Aws::String Email;

            LinkedPlatformAccountModel() :
                PlayFabBaseModel(),
                Platform(),
                PlatformUserId(),
                Username(),
                Email()
            {}

            LinkedPlatformAccountModel(const LinkedPlatformAccountModel& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username),
                Email(src.Email)
            {}

            LinkedPlatformAccountModel(const rapidjson::Value& obj) : LinkedPlatformAccountModel()
            {
                readFromValue(obj);
            }

            ~LinkedPlatformAccountModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.notNull()) { writer.String("Platform"); writeLoginIdentityProviderEnumJSON(Platform, writer); }
                if (PlatformUserId.length() > 0) { writer.String("PlatformUserId"); writer.String(PlatformUserId.c_str()); }
                if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
                if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readLoginIdentityProviderFromValue(Platform_member->value);
                const Value::ConstMemberIterator PlatformUserId_member = obj.FindMember("PlatformUserId");
                if (PlatformUserId_member != obj.MemberEnd() && !PlatformUserId_member->value.IsNull()) PlatformUserId = PlatformUserId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct ValueToDateModel : public PlayFabBaseModel
        {
            Aws::String Currency;
            Uint32 TotalValue;
            Aws::String TotalValueAsDecimal;

            ValueToDateModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(0),
                TotalValueAsDecimal()
            {}

            ValueToDateModel(const ValueToDateModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue),
                TotalValueAsDecimal(src.TotalValueAsDecimal)
            {}

            ValueToDateModel(const rapidjson::Value& obj) : ValueToDateModel()
            {
                readFromValue(obj);
            }

            ~ValueToDateModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Currency.length() > 0) { writer.String("Currency"); writer.String(Currency.c_str()); }
                writer.String("TotalValue"); writer.Uint(TotalValue);
                if (TotalValueAsDecimal.length() > 0) { writer.String("TotalValueAsDecimal"); writer.String(TotalValueAsDecimal.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator TotalValue_member = obj.FindMember("TotalValue");
                if (TotalValue_member != obj.MemberEnd() && !TotalValue_member->value.IsNull()) TotalValue = TotalValue_member->value.GetUint();
                const Value::ConstMemberIterator TotalValueAsDecimal_member = obj.FindMember("TotalValueAsDecimal");
                if (TotalValueAsDecimal_member != obj.MemberEnd() && !TotalValueAsDecimal_member->value.IsNull()) TotalValueAsDecimal = TotalValueAsDecimal_member->value.GetString();

                return true;
            }
        };

        struct VirtualCurrencyBalanceModel : public PlayFabBaseModel
        {
            Aws::String Currency;
            Int32 TotalValue;

            VirtualCurrencyBalanceModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(0)
            {}

            VirtualCurrencyBalanceModel(const VirtualCurrencyBalanceModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue)
            {}

            VirtualCurrencyBalanceModel(const rapidjson::Value& obj) : VirtualCurrencyBalanceModel()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyBalanceModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Currency.length() > 0) { writer.String("Currency"); writer.String(Currency.c_str()); }
                writer.String("TotalValue"); writer.Int(TotalValue);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator TotalValue_member = obj.FindMember("TotalValue");
                if (TotalValue_member != obj.MemberEnd() && !TotalValue_member->value.IsNull()) TotalValue = TotalValue_member->value.GetInt();

                return true;
            }
        };

        struct StatisticModel : public PlayFabBaseModel
        {
            Aws::String Name;
            Int32 Version;
            Int32 Value;

            StatisticModel() :
                PlayFabBaseModel(),
                Name(),
                Version(0),
                Value(0)
            {}

            StatisticModel(const StatisticModel& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Version(src.Version),
                Value(src.Value)
            {}

            StatisticModel(const rapidjson::Value& obj) : StatisticModel()
            {
                readFromValue(obj);
            }

            ~StatisticModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
                writer.String("Version"); writer.Int(Version);
                writer.String("Value"); writer.Int(Value);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();

                return true;
            }
        };

        struct PlayerProfileModel : public PlayFabBaseModel
        {
            Aws::String PublisherId;
            Aws::String TitleId;
            Aws::String PlayerId;
            OptionalTime Created;
            Boxed<LoginIdentityProvider> Origination;
            OptionalTime LastLogin;
            OptionalTime BannedUntil;
            std::list<LocationModel> Locations;
            Aws::String DisplayName;
            Aws::String AvatarUrl;
            std::list<TagModel> Tags;
            std::list<PushNotificationRegistrationModel> PushNotificationRegistrations;
            std::list<LinkedPlatformAccountModel> LinkedAccounts;
            std::list<AdCampaignAttributionModel> AdCampaignAttributions;
            OptionalUint32 TotalValueToDateInUSD;
            std::list<ValueToDateModel> ValuesToDate;
            std::list<VirtualCurrencyBalanceModel> VirtualCurrencyBalances;
            std::list<StatisticModel> Statistics;

            PlayerProfileModel() :
                PlayFabBaseModel(),
                PublisherId(),
                TitleId(),
                PlayerId(),
                Created(),
                Origination(),
                LastLogin(),
                BannedUntil(),
                Locations(),
                DisplayName(),
                AvatarUrl(),
                Tags(),
                PushNotificationRegistrations(),
                LinkedAccounts(),
                AdCampaignAttributions(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                VirtualCurrencyBalances(),
                Statistics()
            {}

            PlayerProfileModel(const PlayerProfileModel& src) :
                PlayFabBaseModel(),
                PublisherId(src.PublisherId),
                TitleId(src.TitleId),
                PlayerId(src.PlayerId),
                Created(src.Created),
                Origination(src.Origination),
                LastLogin(src.LastLogin),
                BannedUntil(src.BannedUntil),
                Locations(src.Locations),
                DisplayName(src.DisplayName),
                AvatarUrl(src.AvatarUrl),
                Tags(src.Tags),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                LinkedAccounts(src.LinkedAccounts),
                AdCampaignAttributions(src.AdCampaignAttributions),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances),
                Statistics(src.Statistics)
            {}

            PlayerProfileModel(const rapidjson::Value& obj) : PlayerProfileModel()
            {
                readFromValue(obj);
            }

            ~PlayerProfileModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PublisherId.length() > 0) { writer.String("PublisherId"); writer.String(PublisherId.c_str()); }
                if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
                if (PlayerId.length() > 0) { writer.String("PlayerId"); writer.String(PlayerId.c_str()); }
                if (Created.notNull()) { writer.String("Created"); writeDatetime(Created, writer); }
                if (Origination.notNull()) { writer.String("Origination"); writeLoginIdentityProviderEnumJSON(Origination, writer); }
                if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
                if (BannedUntil.notNull()) { writer.String("BannedUntil"); writeDatetime(BannedUntil, writer); }
                if (!Locations.empty()) {
    writer.String("Locations");
    writer.StartArray();
    for (std::list<LocationModel>::iterator iter = Locations.begin(); iter != Locations.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (AvatarUrl.length() > 0) { writer.String("AvatarUrl"); writer.String(AvatarUrl.c_str()); }
                if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartArray();
    for (std::list<TagModel>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!PushNotificationRegistrations.empty()) {
    writer.String("PushNotificationRegistrations");
    writer.StartArray();
    for (std::list<PushNotificationRegistrationModel>::iterator iter = PushNotificationRegistrations.begin(); iter != PushNotificationRegistrations.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!LinkedAccounts.empty()) {
    writer.String("LinkedAccounts");
    writer.StartArray();
    for (std::list<LinkedPlatformAccountModel>::iterator iter = LinkedAccounts.begin(); iter != LinkedAccounts.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!AdCampaignAttributions.empty()) {
    writer.String("AdCampaignAttributions");
    writer.StartArray();
    for (std::list<AdCampaignAttributionModel>::iterator iter = AdCampaignAttributions.begin(); iter != AdCampaignAttributions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (TotalValueToDateInUSD.notNull()) { writer.String("TotalValueToDateInUSD"); writer.Uint(TotalValueToDateInUSD); }
                if (!ValuesToDate.empty()) {
    writer.String("ValuesToDate");
    writer.StartArray();
    for (std::list<ValueToDateModel>::iterator iter = ValuesToDate.begin(); iter != ValuesToDate.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!VirtualCurrencyBalances.empty()) {
    writer.String("VirtualCurrencyBalances");
    writer.StartArray();
    for (std::list<VirtualCurrencyBalanceModel>::iterator iter = VirtualCurrencyBalances.begin(); iter != VirtualCurrencyBalances.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!Statistics.empty()) {
    writer.String("Statistics");
    writer.StartArray();
    for (std::list<StatisticModel>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PublisherId_member = obj.FindMember("PublisherId");
                if (PublisherId_member != obj.MemberEnd() && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
                if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readLoginIdentityProviderFromValue(Origination_member->value);
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator BannedUntil_member = obj.FindMember("BannedUntil");
                if (BannedUntil_member != obj.MemberEnd() && !BannedUntil_member->value.IsNull()) BannedUntil = readDatetime(BannedUntil_member->value);
                const Value::ConstMemberIterator Locations_member = obj.FindMember("Locations");
    if (Locations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Locations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Locations.push_back(LocationModel(memberList[i]));
        }
    }
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
                if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(TagModel(memberList[i]));
        }
    }
                const Value::ConstMemberIterator PushNotificationRegistrations_member = obj.FindMember("PushNotificationRegistrations");
    if (PushNotificationRegistrations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PushNotificationRegistrations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PushNotificationRegistrations.push_back(PushNotificationRegistrationModel(memberList[i]));
        }
    }
                const Value::ConstMemberIterator LinkedAccounts_member = obj.FindMember("LinkedAccounts");
    if (LinkedAccounts_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = LinkedAccounts_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            LinkedAccounts.push_back(LinkedPlatformAccountModel(memberList[i]));
        }
    }
                const Value::ConstMemberIterator AdCampaignAttributions_member = obj.FindMember("AdCampaignAttributions");
    if (AdCampaignAttributions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AdCampaignAttributions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AdCampaignAttributions.push_back(AdCampaignAttributionModel(memberList[i]));
        }
    }
                const Value::ConstMemberIterator TotalValueToDateInUSD_member = obj.FindMember("TotalValueToDateInUSD");
                if (TotalValueToDateInUSD_member != obj.MemberEnd() && !TotalValueToDateInUSD_member->value.IsNull()) TotalValueToDateInUSD = TotalValueToDateInUSD_member->value.GetUint();
                const Value::ConstMemberIterator ValuesToDate_member = obj.FindMember("ValuesToDate");
    if (ValuesToDate_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ValuesToDate_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ValuesToDate.push_back(ValueToDateModel(memberList[i]));
        }
    }
                const Value::ConstMemberIterator VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
    if (VirtualCurrencyBalances_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = VirtualCurrencyBalances_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            VirtualCurrencyBalances.push_back(VirtualCurrencyBalanceModel(memberList[i]));
        }
    }
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statistics.push_back(StatisticModel(memberList[i]));
        }
    }

                return true;
            }
        };

        struct PlayerLeaderboardEntry : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String DisplayName;
            Int32 StatValue;
            Int32 Position;
            PlayerProfileModel* Profile;

            PlayerLeaderboardEntry() :
                PlayFabBaseModel(),
                PlayFabId(),
                DisplayName(),
                StatValue(0),
                Position(0),
                Profile(nullptr)
            {}

            PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DisplayName(src.DisplayName),
                StatValue(src.StatValue),
                Position(src.Position),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : nullptr)
            {}

            PlayerLeaderboardEntry(const rapidjson::Value& obj) : PlayerLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~PlayerLeaderboardEntry()
            {
                if (Profile != nullptr) delete Profile;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                writer.String("StatValue"); writer.Int(StatValue);
                writer.String("Position"); writer.Int(Position);
                if (Profile != nullptr) { writer.String("Profile"); Profile->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
                if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();
                const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
                if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();
                const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
                if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new PlayerProfileModel(Profile_member->value);

                return true;
            }
        };

        struct GetLeaderboardAroundUserResult : public PlayFabBaseModel
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Int32 Version;
            OptionalTime NextReset;

            GetLeaderboardAroundUserResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                Version(0),
                NextReset()
            {}

            GetLeaderboardAroundUserResult(const GetLeaderboardAroundUserResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                Version(src.Version),
                NextReset(src.NextReset)
            {}

            GetLeaderboardAroundUserResult(const rapidjson::Value& obj) : GetLeaderboardAroundUserResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<PlayerLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.String("Version"); writer.Int(Version);
                if (NextReset.notNull()) { writer.String("NextReset"); writeDatetime(NextReset, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
        }
    }
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
                if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);

                return true;
            }
        };

        struct GetLeaderboardForUsersCharactersRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Aws::String PlayFabId;
            Int32 MaxResultsCount;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                PlayFabId(),
                MaxResultsCount(0)
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                PlayFabId(src.PlayFabId),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetLeaderboardForUsersCharactersRequest(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardForUsersCharactersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

                return true;
            }
        };

        struct GetLeaderboardForUsersCharactersResult : public PlayFabBaseModel
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetLeaderboardForUsersCharactersResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardForUsersCharactersResult(const GetLeaderboardForUsersCharactersResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardForUsersCharactersResult(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardForUsersCharactersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<CharacterLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetLeaderboardRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Int32 StartPosition;
            Int32 MaxResultsCount;
            PlayerProfileViewConstraints* ProfileConstraints;
            OptionalInt32 Version;
            OptionalBool UseSpecificVersion;

            GetLeaderboardRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount(0),
                ProfileConstraints(nullptr),
                Version(),
                UseSpecificVersion()
            {}

            GetLeaderboardRequest(const GetLeaderboardRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr),
                Version(src.Version),
                UseSpecificVersion(src.UseSpecificVersion)
            {}

            GetLeaderboardRequest(const rapidjson::Value& obj) : GetLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                writer.String("StartPosition"); writer.Int(StartPosition);
                writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
                if (ProfileConstraints != nullptr) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
                if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
                if (UseSpecificVersion.notNull()) { writer.String("UseSpecificVersion"); writer.Bool(UseSpecificVersion); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator UseSpecificVersion_member = obj.FindMember("UseSpecificVersion");
                if (UseSpecificVersion_member != obj.MemberEnd() && !UseSpecificVersion_member->value.IsNull()) UseSpecificVersion = UseSpecificVersion_member->value.GetBool();

                return true;
            }
        };

        struct GetLeaderboardResult : public PlayFabBaseModel
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Int32 Version;
            OptionalTime NextReset;

            GetLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                Version(0),
                NextReset()
            {}

            GetLeaderboardResult(const GetLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                Version(src.Version),
                NextReset(src.NextReset)
            {}

            GetLeaderboardResult(const rapidjson::Value& obj) : GetLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<PlayerLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.String("Version"); writer.Int(Version);
                if (NextReset.notNull()) { writer.String("NextReset"); writeDatetime(NextReset, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
        }
    }
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
                if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);

                return true;
            }
        };

        struct GetPlayerCombinedInfoRequestParams : public PlayFabBaseModel
        {
            bool GetUserAccountInfo;
            bool GetUserInventory;
            bool GetUserVirtualCurrency;
            bool GetUserData;
            std::list<Aws::String> UserDataKeys;
            bool GetUserReadOnlyData;
            std::list<Aws::String> UserReadOnlyDataKeys;
            bool GetCharacterInventories;
            bool GetCharacterList;
            bool GetTitleData;
            std::list<Aws::String> TitleDataKeys;
            bool GetPlayerStatistics;
            std::list<Aws::String> PlayerStatisticNames;
            bool GetPlayerProfile;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetPlayerCombinedInfoRequestParams() :
                PlayFabBaseModel(),
                GetUserAccountInfo(false),
                GetUserInventory(false),
                GetUserVirtualCurrency(false),
                GetUserData(false),
                UserDataKeys(),
                GetUserReadOnlyData(false),
                UserReadOnlyDataKeys(),
                GetCharacterInventories(false),
                GetCharacterList(false),
                GetTitleData(false),
                TitleDataKeys(),
                GetPlayerStatistics(false),
                PlayerStatisticNames(),
                GetPlayerProfile(false),
                ProfileConstraints(nullptr)
            {}

            GetPlayerCombinedInfoRequestParams(const GetPlayerCombinedInfoRequestParams& src) :
                PlayFabBaseModel(),
                GetUserAccountInfo(src.GetUserAccountInfo),
                GetUserInventory(src.GetUserInventory),
                GetUserVirtualCurrency(src.GetUserVirtualCurrency),
                GetUserData(src.GetUserData),
                UserDataKeys(src.UserDataKeys),
                GetUserReadOnlyData(src.GetUserReadOnlyData),
                UserReadOnlyDataKeys(src.UserReadOnlyDataKeys),
                GetCharacterInventories(src.GetCharacterInventories),
                GetCharacterList(src.GetCharacterList),
                GetTitleData(src.GetTitleData),
                TitleDataKeys(src.TitleDataKeys),
                GetPlayerStatistics(src.GetPlayerStatistics),
                PlayerStatisticNames(src.PlayerStatisticNames),
                GetPlayerProfile(src.GetPlayerProfile),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetPlayerCombinedInfoRequestParams(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequestParams()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequestParams()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("GetUserAccountInfo"); writer.Bool(GetUserAccountInfo);
                writer.String("GetUserInventory"); writer.Bool(GetUserInventory);
                writer.String("GetUserVirtualCurrency"); writer.Bool(GetUserVirtualCurrency);
                writer.String("GetUserData"); writer.Bool(GetUserData);
                if (!UserDataKeys.empty()) {
    writer.String("UserDataKeys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = UserDataKeys.begin(); iter != UserDataKeys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.String("GetUserReadOnlyData"); writer.Bool(GetUserReadOnlyData);
                if (!UserReadOnlyDataKeys.empty()) {
    writer.String("UserReadOnlyDataKeys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = UserReadOnlyDataKeys.begin(); iter != UserReadOnlyDataKeys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.String("GetCharacterInventories"); writer.Bool(GetCharacterInventories);
                writer.String("GetCharacterList"); writer.Bool(GetCharacterList);
                writer.String("GetTitleData"); writer.Bool(GetTitleData);
                if (!TitleDataKeys.empty()) {
    writer.String("TitleDataKeys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = TitleDataKeys.begin(); iter != TitleDataKeys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.String("GetPlayerStatistics"); writer.Bool(GetPlayerStatistics);
                if (!PlayerStatisticNames.empty()) {
    writer.String("PlayerStatisticNames");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = PlayerStatisticNames.begin(); iter != PlayerStatisticNames.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.String("GetPlayerProfile"); writer.Bool(GetPlayerProfile);
                if (ProfileConstraints != nullptr) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GetUserAccountInfo_member = obj.FindMember("GetUserAccountInfo");
                if (GetUserAccountInfo_member != obj.MemberEnd() && !GetUserAccountInfo_member->value.IsNull()) GetUserAccountInfo = GetUserAccountInfo_member->value.GetBool();
                const Value::ConstMemberIterator GetUserInventory_member = obj.FindMember("GetUserInventory");
                if (GetUserInventory_member != obj.MemberEnd() && !GetUserInventory_member->value.IsNull()) GetUserInventory = GetUserInventory_member->value.GetBool();
                const Value::ConstMemberIterator GetUserVirtualCurrency_member = obj.FindMember("GetUserVirtualCurrency");
                if (GetUserVirtualCurrency_member != obj.MemberEnd() && !GetUserVirtualCurrency_member->value.IsNull()) GetUserVirtualCurrency = GetUserVirtualCurrency_member->value.GetBool();
                const Value::ConstMemberIterator GetUserData_member = obj.FindMember("GetUserData");
                if (GetUserData_member != obj.MemberEnd() && !GetUserData_member->value.IsNull()) GetUserData = GetUserData_member->value.GetBool();
                const Value::ConstMemberIterator UserDataKeys_member = obj.FindMember("UserDataKeys");
    if (UserDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserDataKeys.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator GetUserReadOnlyData_member = obj.FindMember("GetUserReadOnlyData");
                if (GetUserReadOnlyData_member != obj.MemberEnd() && !GetUserReadOnlyData_member->value.IsNull()) GetUserReadOnlyData = GetUserReadOnlyData_member->value.GetBool();
                const Value::ConstMemberIterator UserReadOnlyDataKeys_member = obj.FindMember("UserReadOnlyDataKeys");
    if (UserReadOnlyDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserReadOnlyDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserReadOnlyDataKeys.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator GetCharacterInventories_member = obj.FindMember("GetCharacterInventories");
                if (GetCharacterInventories_member != obj.MemberEnd() && !GetCharacterInventories_member->value.IsNull()) GetCharacterInventories = GetCharacterInventories_member->value.GetBool();
                const Value::ConstMemberIterator GetCharacterList_member = obj.FindMember("GetCharacterList");
                if (GetCharacterList_member != obj.MemberEnd() && !GetCharacterList_member->value.IsNull()) GetCharacterList = GetCharacterList_member->value.GetBool();
                const Value::ConstMemberIterator GetTitleData_member = obj.FindMember("GetTitleData");
                if (GetTitleData_member != obj.MemberEnd() && !GetTitleData_member->value.IsNull()) GetTitleData = GetTitleData_member->value.GetBool();
                const Value::ConstMemberIterator TitleDataKeys_member = obj.FindMember("TitleDataKeys");
    if (TitleDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TitleDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TitleDataKeys.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator GetPlayerStatistics_member = obj.FindMember("GetPlayerStatistics");
                if (GetPlayerStatistics_member != obj.MemberEnd() && !GetPlayerStatistics_member->value.IsNull()) GetPlayerStatistics = GetPlayerStatistics_member->value.GetBool();
                const Value::ConstMemberIterator PlayerStatisticNames_member = obj.FindMember("PlayerStatisticNames");
    if (PlayerStatisticNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatisticNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatisticNames.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator GetPlayerProfile_member = obj.FindMember("GetPlayerProfile");
                if (GetPlayerProfile_member != obj.MemberEnd() && !GetPlayerProfile_member->value.IsNull()) GetPlayerProfile = GetPlayerProfile_member->value.GetBool();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetPlayerCombinedInfoRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            GetPlayerCombinedInfoRequestParams InfoRequestParameters;

            GetPlayerCombinedInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                InfoRequestParameters()
            {}

            GetPlayerCombinedInfoRequest(const GetPlayerCombinedInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                InfoRequestParameters(src.InfoRequestParameters)
            {}

            GetPlayerCombinedInfoRequest(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("InfoRequestParameters"); InfoRequestParameters.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct StatisticValue : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Int32 Value;
            Uint32 Version;

            StatisticValue() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version(0)
            {}

            StatisticValue(const StatisticValue& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticValue(const rapidjson::Value& obj) : StatisticValue()
            {
                readFromValue(obj);
            }

            ~StatisticValue()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
                writer.String("Value"); writer.Int(Value);
                writer.String("Version"); writer.Uint(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

                return true;
            }
        };

        struct GetPlayerCombinedInfoResultPayload : public PlayFabBaseModel
        {
            UserAccountInfo* AccountInfo;
            std::list<ItemInstance> UserInventory;
            std::map<Aws::String, Int32> UserVirtualCurrency;
            std::map<Aws::String, VirtualCurrencyRechargeTime> UserVirtualCurrencyRechargeTimes;
            std::map<Aws::String, UserDataRecord> UserData;
            Uint32 UserDataVersion;
            std::map<Aws::String, UserDataRecord> UserReadOnlyData;
            Uint32 UserReadOnlyDataVersion;
            std::list<CharacterResult> CharacterList;
            std::list<CharacterInventory> CharacterInventories;
            std::map<Aws::String, Aws::String> TitleData;
            std::list<StatisticValue> PlayerStatistics;
            PlayerProfileModel* PlayerProfile;

            GetPlayerCombinedInfoResultPayload() :
                PlayFabBaseModel(),
                AccountInfo(nullptr),
                UserInventory(),
                UserVirtualCurrency(),
                UserVirtualCurrencyRechargeTimes(),
                UserData(),
                UserDataVersion(0),
                UserReadOnlyData(),
                UserReadOnlyDataVersion(0),
                CharacterList(),
                CharacterInventories(),
                TitleData(),
                PlayerStatistics(),
                PlayerProfile(nullptr)
            {}

            GetPlayerCombinedInfoResultPayload(const GetPlayerCombinedInfoResultPayload& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : nullptr),
                UserInventory(src.UserInventory),
                UserVirtualCurrency(src.UserVirtualCurrency),
                UserVirtualCurrencyRechargeTimes(src.UserVirtualCurrencyRechargeTimes),
                UserData(src.UserData),
                UserDataVersion(src.UserDataVersion),
                UserReadOnlyData(src.UserReadOnlyData),
                UserReadOnlyDataVersion(src.UserReadOnlyDataVersion),
                CharacterList(src.CharacterList),
                CharacterInventories(src.CharacterInventories),
                TitleData(src.TitleData),
                PlayerStatistics(src.PlayerStatistics),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : nullptr)
            {}

            GetPlayerCombinedInfoResultPayload(const rapidjson::Value& obj) : GetPlayerCombinedInfoResultPayload()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResultPayload()
            {
                if (AccountInfo != nullptr) delete AccountInfo;
                if (PlayerProfile != nullptr) delete PlayerProfile;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AccountInfo != nullptr) { writer.String("AccountInfo"); AccountInfo->writeJSON(writer); }
                if (!UserInventory.empty()) {
    writer.String("UserInventory");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = UserInventory.begin(); iter != UserInventory.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!UserVirtualCurrency.empty()) {
    writer.String("UserVirtualCurrency");
    writer.StartObject();
    for (std::map<Aws::String, Int32>::iterator iter = UserVirtualCurrency.begin(); iter != UserVirtualCurrency.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
                if (!UserVirtualCurrencyRechargeTimes.empty()) {
    writer.String("UserVirtualCurrencyRechargeTimes");
    writer.StartObject();
    for (std::map<Aws::String, VirtualCurrencyRechargeTime>::iterator iter = UserVirtualCurrencyRechargeTimes.begin(); iter != UserVirtualCurrencyRechargeTimes.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                if (!UserData.empty()) {
    writer.String("UserData");
    writer.StartObject();
    for (std::map<Aws::String, UserDataRecord>::iterator iter = UserData.begin(); iter != UserData.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.String("UserDataVersion"); writer.Uint(UserDataVersion);
                if (!UserReadOnlyData.empty()) {
    writer.String("UserReadOnlyData");
    writer.StartObject();
    for (std::map<Aws::String, UserDataRecord>::iterator iter = UserReadOnlyData.begin(); iter != UserReadOnlyData.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.String("UserReadOnlyDataVersion"); writer.Uint(UserReadOnlyDataVersion);
                if (!CharacterList.empty()) {
    writer.String("CharacterList");
    writer.StartArray();
    for (std::list<CharacterResult>::iterator iter = CharacterList.begin(); iter != CharacterList.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!CharacterInventories.empty()) {
    writer.String("CharacterInventories");
    writer.StartArray();
    for (std::list<CharacterInventory>::iterator iter = CharacterInventories.begin(); iter != CharacterInventories.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!TitleData.empty()) {
    writer.String("TitleData");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = TitleData.begin(); iter != TitleData.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!PlayerStatistics.empty()) {
    writer.String("PlayerStatistics");
    writer.StartArray();
    for (std::list<StatisticValue>::iterator iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (PlayerProfile != nullptr) { writer.String("PlayerProfile"); PlayerProfile->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccountInfo_member = obj.FindMember("AccountInfo");
                if (AccountInfo_member != obj.MemberEnd() && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);
                const Value::ConstMemberIterator UserInventory_member = obj.FindMember("UserInventory");
    if (UserInventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserInventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserInventory.push_back(ItemInstance(memberList[i]));
        }
    }
                const Value::ConstMemberIterator UserVirtualCurrency_member = obj.FindMember("UserVirtualCurrency");
    if (UserVirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserVirtualCurrency_member->value.MemberBegin(); iter != UserVirtualCurrency_member->value.MemberEnd(); ++iter) {
            UserVirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }
                const Value::ConstMemberIterator UserVirtualCurrencyRechargeTimes_member = obj.FindMember("UserVirtualCurrencyRechargeTimes");
    if (UserVirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserVirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != UserVirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
            UserVirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
        }
    }
                const Value::ConstMemberIterator UserData_member = obj.FindMember("UserData");
    if (UserData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserData_member->value.MemberBegin(); iter != UserData_member->value.MemberEnd(); ++iter) {
            UserData[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
                const Value::ConstMemberIterator UserDataVersion_member = obj.FindMember("UserDataVersion");
                if (UserDataVersion_member != obj.MemberEnd() && !UserDataVersion_member->value.IsNull()) UserDataVersion = UserDataVersion_member->value.GetUint();
                const Value::ConstMemberIterator UserReadOnlyData_member = obj.FindMember("UserReadOnlyData");
    if (UserReadOnlyData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserReadOnlyData_member->value.MemberBegin(); iter != UserReadOnlyData_member->value.MemberEnd(); ++iter) {
            UserReadOnlyData[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
                const Value::ConstMemberIterator UserReadOnlyDataVersion_member = obj.FindMember("UserReadOnlyDataVersion");
                if (UserReadOnlyDataVersion_member != obj.MemberEnd() && !UserReadOnlyDataVersion_member->value.IsNull()) UserReadOnlyDataVersion = UserReadOnlyDataVersion_member->value.GetUint();
                const Value::ConstMemberIterator CharacterList_member = obj.FindMember("CharacterList");
    if (CharacterList_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = CharacterList_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            CharacterList.push_back(CharacterResult(memberList[i]));
        }
    }
                const Value::ConstMemberIterator CharacterInventories_member = obj.FindMember("CharacterInventories");
    if (CharacterInventories_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = CharacterInventories_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            CharacterInventories.push_back(CharacterInventory(memberList[i]));
        }
    }
                const Value::ConstMemberIterator TitleData_member = obj.FindMember("TitleData");
    if (TitleData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = TitleData_member->value.MemberBegin(); iter != TitleData_member->value.MemberEnd(); ++iter) {
            TitleData[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
    if (PlayerStatistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatistics.push_back(StatisticValue(memberList[i]));
        }
    }
                const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
                if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = new PlayerProfileModel(PlayerProfile_member->value);

                return true;
            }
        };

        struct GetPlayerCombinedInfoResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            GetPlayerCombinedInfoResultPayload* InfoResultPayload;

            GetPlayerCombinedInfoResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                InfoResultPayload(nullptr)
            {}

            GetPlayerCombinedInfoResult(const GetPlayerCombinedInfoResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                InfoResultPayload(src.InfoResultPayload ? new GetPlayerCombinedInfoResultPayload(*src.InfoResultPayload) : nullptr)
            {}

            GetPlayerCombinedInfoResult(const rapidjson::Value& obj) : GetPlayerCombinedInfoResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResult()
            {
                if (InfoResultPayload != nullptr) delete InfoResultPayload;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (InfoResultPayload != nullptr) { writer.String("InfoResultPayload"); InfoResultPayload->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator InfoResultPayload_member = obj.FindMember("InfoResultPayload");
                if (InfoResultPayload_member != obj.MemberEnd() && !InfoResultPayload_member->value.IsNull()) InfoResultPayload = new GetPlayerCombinedInfoResultPayload(InfoResultPayload_member->value);

                return true;
            }
        };

        struct GetPlayerProfileRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetPlayerProfileRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                ProfileConstraints(nullptr)
            {}

            GetPlayerProfileRequest(const GetPlayerProfileRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetPlayerProfileRequest(const rapidjson::Value& obj) : GetPlayerProfileRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (ProfileConstraints != nullptr) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetPlayerProfileResult : public PlayFabBaseModel
        {
            PlayerProfileModel* PlayerProfile;

            GetPlayerProfileResult() :
                PlayFabBaseModel(),
                PlayerProfile(nullptr)
            {}

            GetPlayerProfileResult(const GetPlayerProfileResult& src) :
                PlayFabBaseModel(),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : nullptr)
            {}

            GetPlayerProfileResult(const rapidjson::Value& obj) : GetPlayerProfileResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileResult()
            {
                if (PlayerProfile != nullptr) delete PlayerProfile;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayerProfile != nullptr) { writer.String("PlayerProfile"); PlayerProfile->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
                if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = new PlayerProfileModel(PlayerProfile_member->value);

                return true;
            }
        };

        struct GetPlayerSegmentsResult : public PlayFabBaseModel
        {
            std::list<GetSegmentResult> Segments;

            GetPlayerSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetPlayerSegmentsResult(const GetPlayerSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetPlayerSegmentsResult(const rapidjson::Value& obj) : GetPlayerSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerSegmentsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Segments.empty()) {
    writer.String("Segments");
    writer.StartArray();
    for (std::list<GetSegmentResult>::iterator iter = Segments.begin(); iter != Segments.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Segments_member = obj.FindMember("Segments");
    if (Segments_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Segments_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Segments.push_back(GetSegmentResult(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayersInSegmentRequest : public PlayFabBaseModel
        {
            Aws::String SegmentId;
            OptionalUint32 SecondsToLive;
            OptionalUint32 MaxBatchSize;
            Aws::String ContinuationToken;

            GetPlayersInSegmentRequest() :
                PlayFabBaseModel(),
                SegmentId(),
                SecondsToLive(),
                MaxBatchSize(),
                ContinuationToken()
            {}

            GetPlayersInSegmentRequest(const GetPlayersInSegmentRequest& src) :
                PlayFabBaseModel(),
                SegmentId(src.SegmentId),
                SecondsToLive(src.SecondsToLive),
                MaxBatchSize(src.MaxBatchSize),
                ContinuationToken(src.ContinuationToken)
            {}

            GetPlayersInSegmentRequest(const rapidjson::Value& obj) : GetPlayersInSegmentRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SegmentId"); writer.String(SegmentId.c_str());
                if (SecondsToLive.notNull()) { writer.String("SecondsToLive"); writer.Uint(SecondsToLive); }
                if (MaxBatchSize.notNull()) { writer.String("MaxBatchSize"); writer.Uint(MaxBatchSize); }
                if (ContinuationToken.length() > 0) { writer.String("ContinuationToken"); writer.String(ContinuationToken.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SegmentId_member = obj.FindMember("SegmentId");
                if (SegmentId_member != obj.MemberEnd() && !SegmentId_member->value.IsNull()) SegmentId = SegmentId_member->value.GetString();
                const Value::ConstMemberIterator SecondsToLive_member = obj.FindMember("SecondsToLive");
                if (SecondsToLive_member != obj.MemberEnd() && !SecondsToLive_member->value.IsNull()) SecondsToLive = SecondsToLive_member->value.GetUint();
                const Value::ConstMemberIterator MaxBatchSize_member = obj.FindMember("MaxBatchSize");
                if (MaxBatchSize_member != obj.MemberEnd() && !MaxBatchSize_member->value.IsNull()) MaxBatchSize = MaxBatchSize_member->value.GetUint();
                const Value::ConstMemberIterator ContinuationToken_member = obj.FindMember("ContinuationToken");
                if (ContinuationToken_member != obj.MemberEnd() && !ContinuationToken_member->value.IsNull()) ContinuationToken = ContinuationToken_member->value.GetString();

                return true;
            }
        };

        struct PlayerLocation : public PlayFabBaseModel
        {
            ContinentCode pfContinentCode;
            CountryCode pfCountryCode;
            Aws::String City;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            PlayerLocation() :
                PlayFabBaseModel(),
                pfContinentCode(),
                pfCountryCode(),
                City(),
                Latitude(),
                Longitude()
            {}

            PlayerLocation(const PlayerLocation& src) :
                PlayFabBaseModel(),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                City(src.City),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            PlayerLocation(const rapidjson::Value& obj) : PlayerLocation()
            {
                readFromValue(obj);
            }

            ~PlayerLocation()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ContinentCode"); writeContinentCodeEnumJSON(pfContinentCode, writer);
                writer.String("CountryCode"); writeCountryCodeEnumJSON(pfCountryCode, writer);
                if (City.length() > 0) { writer.String("City"); writer.String(City.c_str()); }
                if (Latitude.notNull()) { writer.String("Latitude"); writer.Double(Latitude); }
                if (Longitude.notNull()) { writer.String("Longitude"); writer.Double(Longitude); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ContinentCode_member = obj.FindMember("ContinentCode");
                if (ContinentCode_member != obj.MemberEnd() && !ContinentCode_member->value.IsNull()) pfContinentCode = readContinentCodeFromValue(ContinentCode_member->value);
                const Value::ConstMemberIterator CountryCode_member = obj.FindMember("CountryCode");
                if (CountryCode_member != obj.MemberEnd() && !CountryCode_member->value.IsNull()) pfCountryCode = readCountryCodeFromValue(CountryCode_member->value);
                const Value::ConstMemberIterator City_member = obj.FindMember("City");
                if (City_member != obj.MemberEnd() && !City_member->value.IsNull()) City = City_member->value.GetString();
                const Value::ConstMemberIterator Latitude_member = obj.FindMember("Latitude");
                if (Latitude_member != obj.MemberEnd() && !Latitude_member->value.IsNull()) Latitude = Latitude_member->value.GetDouble();
                const Value::ConstMemberIterator Longitude_member = obj.FindMember("Longitude");
                if (Longitude_member != obj.MemberEnd() && !Longitude_member->value.IsNull()) Longitude = Longitude_member->value.GetDouble();

                return true;
            }
        };

        struct PushNotificationRegistration : public PlayFabBaseModel
        {
            Boxed<PushNotificationPlatform> Platform;
            Aws::String NotificationEndpointARN;

            PushNotificationRegistration() :
                PlayFabBaseModel(),
                Platform(),
                NotificationEndpointARN()
            {}

            PushNotificationRegistration(const PushNotificationRegistration& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                NotificationEndpointARN(src.NotificationEndpointARN)
            {}

            PushNotificationRegistration(const rapidjson::Value& obj) : PushNotificationRegistration()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistration()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.notNull()) { writer.String("Platform"); writePushNotificationPlatformEnumJSON(Platform, writer); }
                if (NotificationEndpointARN.length() > 0) { writer.String("NotificationEndpointARN"); writer.String(NotificationEndpointARN.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushNotificationPlatformFromValue(Platform_member->value);
                const Value::ConstMemberIterator NotificationEndpointARN_member = obj.FindMember("NotificationEndpointARN");
                if (NotificationEndpointARN_member != obj.MemberEnd() && !NotificationEndpointARN_member->value.IsNull()) NotificationEndpointARN = NotificationEndpointARN_member->value.GetString();

                return true;
            }
        };

        struct PlayerLinkedAccount : public PlayFabBaseModel
        {
            Boxed<LoginIdentityProvider> Platform;
            Aws::String PlatformUserId;
            Aws::String Username;
            Aws::String Email;

            PlayerLinkedAccount() :
                PlayFabBaseModel(),
                Platform(),
                PlatformUserId(),
                Username(),
                Email()
            {}

            PlayerLinkedAccount(const PlayerLinkedAccount& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username),
                Email(src.Email)
            {}

            PlayerLinkedAccount(const rapidjson::Value& obj) : PlayerLinkedAccount()
            {
                readFromValue(obj);
            }

            ~PlayerLinkedAccount()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.notNull()) { writer.String("Platform"); writeLoginIdentityProviderEnumJSON(Platform, writer); }
                if (PlatformUserId.length() > 0) { writer.String("PlatformUserId"); writer.String(PlatformUserId.c_str()); }
                if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
                if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readLoginIdentityProviderFromValue(Platform_member->value);
                const Value::ConstMemberIterator PlatformUserId_member = obj.FindMember("PlatformUserId");
                if (PlatformUserId_member != obj.MemberEnd() && !PlatformUserId_member->value.IsNull()) PlatformUserId = PlatformUserId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct PlayerStatistic : public PlayFabBaseModel
        {
            Aws::String Id;
            Int32 StatisticVersion;
            Int32 StatisticValue;
            Aws::String Name;

            PlayerStatistic() :
                PlayFabBaseModel(),
                Id(),
                StatisticVersion(0),
                StatisticValue(0),
                Name()
            {}

            PlayerStatistic(const PlayerStatistic& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                StatisticVersion(src.StatisticVersion),
                StatisticValue(src.StatisticValue),
                Name(src.Name)
            {}

            PlayerStatistic(const rapidjson::Value& obj) : PlayerStatistic()
            {
                readFromValue(obj);
            }

            ~PlayerStatistic()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }
                writer.String("StatisticVersion"); writer.Int(StatisticVersion);
                writer.String("StatisticValue"); writer.Int(StatisticValue);
                if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator StatisticVersion_member = obj.FindMember("StatisticVersion");
                if (StatisticVersion_member != obj.MemberEnd() && !StatisticVersion_member->value.IsNull()) StatisticVersion = StatisticVersion_member->value.GetInt();
                const Value::ConstMemberIterator StatisticValue_member = obj.FindMember("StatisticValue");
                if (StatisticValue_member != obj.MemberEnd() && !StatisticValue_member->value.IsNull()) StatisticValue = StatisticValue_member->value.GetInt();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

                return true;
            }
        };

        struct PlayerProfile : public PlayFabBaseModel
        {
            Aws::String PlayerId;
            Aws::String TitleId;
            Aws::String DisplayName;
            Aws::String PublisherId;
            Boxed<LoginIdentityProvider> Origination;
            OptionalTime Created;
            OptionalTime LastLogin;
            OptionalTime BannedUntil;
            Aws::String AvatarUrl;
            std::map<Aws::String, Int32> Statistics;
            OptionalUint32 TotalValueToDateInUSD;
            std::map<Aws::String, Uint32> ValuesToDate;
            std::list<Aws::String> Tags;
            std::map<Aws::String, PlayerLocation> Locations;
            std::map<Aws::String, Int32> VirtualCurrencyBalances;
            std::list<AdCampaignAttribution> AdCampaignAttributions;
            std::list<PushNotificationRegistration> PushNotificationRegistrations;
            std::list<PlayerLinkedAccount> LinkedAccounts;
            std::list<PlayerStatistic> PlayerStatistics;

            PlayerProfile() :
                PlayFabBaseModel(),
                PlayerId(),
                TitleId(),
                DisplayName(),
                PublisherId(),
                Origination(),
                Created(),
                LastLogin(),
                BannedUntil(),
                AvatarUrl(),
                Statistics(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                Tags(),
                Locations(),
                VirtualCurrencyBalances(),
                AdCampaignAttributions(),
                PushNotificationRegistrations(),
                LinkedAccounts(),
                PlayerStatistics()
            {}

            PlayerProfile(const PlayerProfile& src) :
                PlayFabBaseModel(),
                PlayerId(src.PlayerId),
                TitleId(src.TitleId),
                DisplayName(src.DisplayName),
                PublisherId(src.PublisherId),
                Origination(src.Origination),
                Created(src.Created),
                LastLogin(src.LastLogin),
                BannedUntil(src.BannedUntil),
                AvatarUrl(src.AvatarUrl),
                Statistics(src.Statistics),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                Tags(src.Tags),
                Locations(src.Locations),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances),
                AdCampaignAttributions(src.AdCampaignAttributions),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                LinkedAccounts(src.LinkedAccounts),
                PlayerStatistics(src.PlayerStatistics)
            {}

            PlayerProfile(const rapidjson::Value& obj) : PlayerProfile()
            {
                readFromValue(obj);
            }

            ~PlayerProfile()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayerId.length() > 0) { writer.String("PlayerId"); writer.String(PlayerId.c_str()); }
                if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (PublisherId.length() > 0) { writer.String("PublisherId"); writer.String(PublisherId.c_str()); }
                if (Origination.notNull()) { writer.String("Origination"); writeLoginIdentityProviderEnumJSON(Origination, writer); }
                if (Created.notNull()) { writer.String("Created"); writeDatetime(Created, writer); }
                if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
                if (BannedUntil.notNull()) { writer.String("BannedUntil"); writeDatetime(BannedUntil, writer); }
                if (AvatarUrl.length() > 0) { writer.String("AvatarUrl"); writer.String(AvatarUrl.c_str()); }
                if (!Statistics.empty()) {
    writer.String("Statistics");
    writer.StartObject();
    for (std::map<Aws::String, Int32>::iterator iter = Statistics.begin(); iter != Statistics.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
                if (TotalValueToDateInUSD.notNull()) { writer.String("TotalValueToDateInUSD"); writer.Uint(TotalValueToDateInUSD); }
                if (!ValuesToDate.empty()) {
    writer.String("ValuesToDate");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = ValuesToDate.begin(); iter != ValuesToDate.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!Locations.empty()) {
    writer.String("Locations");
    writer.StartObject();
    for (std::map<Aws::String, PlayerLocation>::iterator iter = Locations.begin(); iter != Locations.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                if (!VirtualCurrencyBalances.empty()) {
    writer.String("VirtualCurrencyBalances");
    writer.StartObject();
    for (std::map<Aws::String, Int32>::iterator iter = VirtualCurrencyBalances.begin(); iter != VirtualCurrencyBalances.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
                if (!AdCampaignAttributions.empty()) {
    writer.String("AdCampaignAttributions");
    writer.StartArray();
    for (std::list<AdCampaignAttribution>::iterator iter = AdCampaignAttributions.begin(); iter != AdCampaignAttributions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!PushNotificationRegistrations.empty()) {
    writer.String("PushNotificationRegistrations");
    writer.StartArray();
    for (std::list<PushNotificationRegistration>::iterator iter = PushNotificationRegistrations.begin(); iter != PushNotificationRegistrations.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!LinkedAccounts.empty()) {
    writer.String("LinkedAccounts");
    writer.StartArray();
    for (std::list<PlayerLinkedAccount>::iterator iter = LinkedAccounts.begin(); iter != LinkedAccounts.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!PlayerStatistics.empty()) {
    writer.String("PlayerStatistics");
    writer.StartArray();
    for (std::list<PlayerStatistic>::iterator iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
                if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator PublisherId_member = obj.FindMember("PublisherId");
                if (PublisherId_member != obj.MemberEnd() && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readLoginIdentityProviderFromValue(Origination_member->value);
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator BannedUntil_member = obj.FindMember("BannedUntil");
                if (BannedUntil_member != obj.MemberEnd() && !BannedUntil_member->value.IsNull()) BannedUntil = readDatetime(BannedUntil_member->value);
                const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
                if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Statistics_member->value.MemberBegin(); iter != Statistics_member->value.MemberEnd(); ++iter) {
            Statistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }
                const Value::ConstMemberIterator TotalValueToDateInUSD_member = obj.FindMember("TotalValueToDateInUSD");
                if (TotalValueToDateInUSD_member != obj.MemberEnd() && !TotalValueToDateInUSD_member->value.IsNull()) TotalValueToDateInUSD = TotalValueToDateInUSD_member->value.GetUint();
                const Value::ConstMemberIterator ValuesToDate_member = obj.FindMember("ValuesToDate");
    if (ValuesToDate_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = ValuesToDate_member->value.MemberBegin(); iter != ValuesToDate_member->value.MemberEnd(); ++iter) {
            ValuesToDate[iter->name.GetString()] = iter->value.GetUint();
        }
    }
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator Locations_member = obj.FindMember("Locations");
    if (Locations_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Locations_member->value.MemberBegin(); iter != Locations_member->value.MemberEnd(); ++iter) {
            Locations[iter->name.GetString()] = PlayerLocation(iter->value);
        }
    }
                const Value::ConstMemberIterator VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
    if (VirtualCurrencyBalances_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyBalances_member->value.MemberBegin(); iter != VirtualCurrencyBalances_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyBalances[iter->name.GetString()] = iter->value.GetInt();
        }
    }
                const Value::ConstMemberIterator AdCampaignAttributions_member = obj.FindMember("AdCampaignAttributions");
    if (AdCampaignAttributions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AdCampaignAttributions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AdCampaignAttributions.push_back(AdCampaignAttribution(memberList[i]));
        }
    }
                const Value::ConstMemberIterator PushNotificationRegistrations_member = obj.FindMember("PushNotificationRegistrations");
    if (PushNotificationRegistrations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PushNotificationRegistrations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PushNotificationRegistrations.push_back(PushNotificationRegistration(memberList[i]));
        }
    }
                const Value::ConstMemberIterator LinkedAccounts_member = obj.FindMember("LinkedAccounts");
    if (LinkedAccounts_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = LinkedAccounts_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            LinkedAccounts.push_back(PlayerLinkedAccount(memberList[i]));
        }
    }
                const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
    if (PlayerStatistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatistics.push_back(PlayerStatistic(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayersInSegmentResult : public PlayFabBaseModel
        {
            Int32 ProfilesInSegment;
            Aws::String ContinuationToken;
            std::list<PlayerProfile> PlayerProfiles;

            GetPlayersInSegmentResult() :
                PlayFabBaseModel(),
                ProfilesInSegment(0),
                ContinuationToken(),
                PlayerProfiles()
            {}

            GetPlayersInSegmentResult(const GetPlayersInSegmentResult& src) :
                PlayFabBaseModel(),
                ProfilesInSegment(src.ProfilesInSegment),
                ContinuationToken(src.ContinuationToken),
                PlayerProfiles(src.PlayerProfiles)
            {}

            GetPlayersInSegmentResult(const rapidjson::Value& obj) : GetPlayersInSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ProfilesInSegment"); writer.Int(ProfilesInSegment);
                if (ContinuationToken.length() > 0) { writer.String("ContinuationToken"); writer.String(ContinuationToken.c_str()); }
                if (!PlayerProfiles.empty()) {
    writer.String("PlayerProfiles");
    writer.StartArray();
    for (std::list<PlayerProfile>::iterator iter = PlayerProfiles.begin(); iter != PlayerProfiles.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ProfilesInSegment_member = obj.FindMember("ProfilesInSegment");
                if (ProfilesInSegment_member != obj.MemberEnd() && !ProfilesInSegment_member->value.IsNull()) ProfilesInSegment = ProfilesInSegment_member->value.GetInt();
                const Value::ConstMemberIterator ContinuationToken_member = obj.FindMember("ContinuationToken");
                if (ContinuationToken_member != obj.MemberEnd() && !ContinuationToken_member->value.IsNull()) ContinuationToken = ContinuationToken_member->value.GetString();
                const Value::ConstMemberIterator PlayerProfiles_member = obj.FindMember("PlayerProfiles");
    if (PlayerProfiles_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerProfiles_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerProfiles.push_back(PlayerProfile(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayersSegmentsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;

            GetPlayersSegmentsRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetPlayersSegmentsRequest(const GetPlayersSegmentsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayersSegmentsRequest(const rapidjson::Value& obj) : GetPlayersSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersSegmentsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct StatisticNameVersion : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Uint32 Version;

            StatisticNameVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0)
            {}

            StatisticNameVersion(const StatisticNameVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            StatisticNameVersion(const rapidjson::Value& obj) : StatisticNameVersion()
            {
                readFromValue(obj);
            }

            ~StatisticNameVersion()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                writer.String("Version"); writer.Uint(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

                return true;
            }
        };

        struct GetPlayerStatisticsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::list<Aws::String> StatisticNames;
            std::list<StatisticNameVersion> StatisticNameVersions;

            GetPlayerStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                StatisticNames(),
                StatisticNameVersions()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                StatisticNames(src.StatisticNames),
                StatisticNameVersions(src.StatisticNameVersions)
            {}

            GetPlayerStatisticsRequest(const rapidjson::Value& obj) : GetPlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (!StatisticNames.empty()) {
    writer.String("StatisticNames");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = StatisticNames.begin(); iter != StatisticNames.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!StatisticNameVersions.empty()) {
    writer.String("StatisticNameVersions");
    writer.StartArray();
    for (std::list<StatisticNameVersion>::iterator iter = StatisticNameVersions.begin(); iter != StatisticNameVersions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator StatisticNames_member = obj.FindMember("StatisticNames");
    if (StatisticNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = StatisticNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            StatisticNames.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator StatisticNameVersions_member = obj.FindMember("StatisticNameVersions");
    if (StatisticNameVersions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = StatisticNameVersions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            StatisticNameVersions.push_back(StatisticNameVersion(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayerStatisticsResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::list<StatisticValue> Statistics;

            GetPlayerStatisticsResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Statistics()
            {}

            GetPlayerStatisticsResult(const GetPlayerStatisticsResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Statistics(src.Statistics)
            {}

            GetPlayerStatisticsResult(const rapidjson::Value& obj) : GetPlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (!Statistics.empty()) {
    writer.String("Statistics");
    writer.StartArray();
    for (std::list<StatisticValue>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statistics.push_back(StatisticValue(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayerStatisticVersionsRequest : public PlayFabBaseModel
        {
            Aws::String StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName)
            {}

            GetPlayerStatisticVersionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            Uint32 Version;
            OptionalTime ScheduledActivationTime;
            time_t ActivationTime;
            OptionalTime ScheduledDeactivationTime;
            OptionalTime DeactivationTime;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0),
                ScheduledActivationTime(),
                ActivationTime(0),
                ScheduledDeactivationTime(),
                DeactivationTime()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ActivationTime(src.ActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                DeactivationTime(src.DeactivationTime)
            {}

            PlayerStatisticVersion(const rapidjson::Value& obj) : PlayerStatisticVersion()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticVersion()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
                writer.String("Version"); writer.Uint(Version);
                if (ScheduledActivationTime.notNull()) { writer.String("ScheduledActivationTime"); writeDatetime(ScheduledActivationTime, writer); }
                writer.String("ActivationTime"); writeDatetime(ActivationTime, writer);
                if (ScheduledDeactivationTime.notNull()) { writer.String("ScheduledDeactivationTime"); writeDatetime(ScheduledDeactivationTime, writer); }
                if (DeactivationTime.notNull()) { writer.String("DeactivationTime"); writeDatetime(DeactivationTime, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();
                const Value::ConstMemberIterator ScheduledActivationTime_member = obj.FindMember("ScheduledActivationTime");
                if (ScheduledActivationTime_member != obj.MemberEnd() && !ScheduledActivationTime_member->value.IsNull()) ScheduledActivationTime = readDatetime(ScheduledActivationTime_member->value);
                const Value::ConstMemberIterator ActivationTime_member = obj.FindMember("ActivationTime");
                if (ActivationTime_member != obj.MemberEnd() && !ActivationTime_member->value.IsNull()) ActivationTime = readDatetime(ActivationTime_member->value);
                const Value::ConstMemberIterator ScheduledDeactivationTime_member = obj.FindMember("ScheduledDeactivationTime");
                if (ScheduledDeactivationTime_member != obj.MemberEnd() && !ScheduledDeactivationTime_member->value.IsNull()) ScheduledDeactivationTime = readDatetime(ScheduledDeactivationTime_member->value);
                const Value::ConstMemberIterator DeactivationTime_member = obj.FindMember("DeactivationTime");
                if (DeactivationTime_member != obj.MemberEnd() && !DeactivationTime_member->value.IsNull()) DeactivationTime = readDatetime(DeactivationTime_member->value);

                return true;
            }
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabBaseModel
        {
            std::list<PlayerStatisticVersion> StatisticVersions;

            GetPlayerStatisticVersionsResult() :
                PlayFabBaseModel(),
                StatisticVersions()
            {}

            GetPlayerStatisticVersionsResult(const GetPlayerStatisticVersionsResult& src) :
                PlayFabBaseModel(),
                StatisticVersions(src.StatisticVersions)
            {}

            GetPlayerStatisticVersionsResult(const rapidjson::Value& obj) : GetPlayerStatisticVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!StatisticVersions.empty()) {
    writer.String("StatisticVersions");
    writer.StartArray();
    for (std::list<PlayerStatisticVersion>::iterator iter = StatisticVersions.begin(); iter != StatisticVersions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticVersions_member = obj.FindMember("StatisticVersions");
    if (StatisticVersions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = StatisticVersions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            StatisticVersions.push_back(PlayerStatisticVersion(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayerTagsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String Namespace;

            GetPlayerTagsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Namespace()
            {}

            GetPlayerTagsRequest(const GetPlayerTagsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Namespace(src.Namespace)
            {}

            GetPlayerTagsRequest(const rapidjson::Value& obj) : GetPlayerTagsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (Namespace.length() > 0) { writer.String("Namespace"); writer.String(Namespace.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Namespace_member = obj.FindMember("Namespace");
                if (Namespace_member != obj.MemberEnd() && !Namespace_member->value.IsNull()) Namespace = Namespace_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerTagsResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::list<Aws::String> Tags;

            GetPlayerTagsResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Tags()
            {}

            GetPlayerTagsResult(const GetPlayerTagsResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            GetPlayerTagsResult(const rapidjson::Value& obj) : GetPlayerTagsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("Tags");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> FacebookIDs;

            GetPlayFabIDsFromFacebookIDsRequest() :
                PlayFabBaseModel(),
                FacebookIDs()
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const GetPlayFabIDsFromFacebookIDsRequest& src) :
                PlayFabBaseModel(),
                FacebookIDs(src.FacebookIDs)
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("FacebookIDs");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = FacebookIDs.begin(); iter != FacebookIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookIDs_member = obj.FindMember("FacebookIDs");
    if (FacebookIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = FacebookIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            FacebookIDs.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsResult : public PlayFabBaseModel
        {
            std::list<FacebookPlayFabIdPair> Data;

            GetPlayFabIDsFromFacebookIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromFacebookIDsResult(const GetPlayFabIDsFromFacebookIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromFacebookIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartArray();
    for (std::list<FacebookPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(FacebookPlayFabIdPair(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPlayFabIDsFromSteamIDsRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> SteamStringIDs;

            GetPlayFabIDsFromSteamIDsRequest() :
                PlayFabBaseModel(),
                SteamStringIDs()
            {}

            GetPlayFabIDsFromSteamIDsRequest(const GetPlayFabIDsFromSteamIDsRequest& src) :
                PlayFabBaseModel(),
                SteamStringIDs(src.SteamStringIDs)
            {}

            GetPlayFabIDsFromSteamIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!SteamStringIDs.empty()) {
    writer.String("SteamStringIDs");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = SteamStringIDs.begin(); iter != SteamStringIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamStringIDs_member = obj.FindMember("SteamStringIDs");
    if (SteamStringIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = SteamStringIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            SteamStringIDs.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct SteamPlayFabIdPair : public PlayFabBaseModel
        {
            Aws::String SteamStringId;
            Aws::String PlayFabId;

            SteamPlayFabIdPair() :
                PlayFabBaseModel(),
                SteamStringId(),
                PlayFabId()
            {}

            SteamPlayFabIdPair(const SteamPlayFabIdPair& src) :
                PlayFabBaseModel(),
                SteamStringId(src.SteamStringId),
                PlayFabId(src.PlayFabId)
            {}

            SteamPlayFabIdPair(const rapidjson::Value& obj) : SteamPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~SteamPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SteamStringId.length() > 0) { writer.String("SteamStringId"); writer.String(SteamStringId.c_str()); }
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamStringId_member = obj.FindMember("SteamStringId");
                if (SteamStringId_member != obj.MemberEnd() && !SteamStringId_member->value.IsNull()) SteamStringId = SteamStringId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromSteamIDsResult : public PlayFabBaseModel
        {
            std::list<SteamPlayFabIdPair> Data;

            GetPlayFabIDsFromSteamIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromSteamIDsResult(const GetPlayFabIDsFromSteamIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromSteamIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartArray();
    for (std::list<SteamPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(SteamPlayFabIdPair(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetPublisherDataRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> Keys;

            GetPublisherDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetPublisherDataRequest(const GetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetPublisherDataRequest(const rapidjson::Value& obj) : GetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Keys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GetPublisherDataResult : public PlayFabBaseModel
        {
            std::map<Aws::String, Aws::String> Data;

            GetPublisherDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPublisherDataResult(const GetPublisherDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPublisherDataResult(const rapidjson::Value& obj) : GetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct GetRandomResultTablesRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            std::list<Aws::String> TableIDs;

            GetRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                TableIDs()
            {}

            GetRandomResultTablesRequest(const GetRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                TableIDs(src.TableIDs)
            {}

            GetRandomResultTablesRequest(const rapidjson::Value& obj) : GetRandomResultTablesRequest()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("TableIDs");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = TableIDs.begin(); iter != TableIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator TableIDs_member = obj.FindMember("TableIDs");
    if (TableIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TableIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TableIDs.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        inline void writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ResultTableNodeTypeItemId: writer.String("ItemId"); break;
            case ResultTableNodeTypeTableId: writer.String("TableId"); break;

            }
        }

        inline ResultTableNodeType readResultTableNodeTypeFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, ResultTableNodeType> _ResultTableNodeTypeMap;
            if (_ResultTableNodeTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ResultTableNodeTypeMap["ItemId"] = ResultTableNodeTypeItemId;
                _ResultTableNodeTypeMap["TableId"] = ResultTableNodeTypeTableId;

            }

            auto output = _ResultTableNodeTypeMap.find(obj.GetString());
            if (output != _ResultTableNodeTypeMap.end())
                return output->second;

            return ResultTableNodeTypeItemId; // Basically critical fail
        }

        struct ResultTableNode : public PlayFabBaseModel
        {
            ResultTableNodeType ResultItemType;
            Aws::String ResultItem;
            Int32 Weight;

            ResultTableNode() :
                PlayFabBaseModel(),
                ResultItemType(),
                ResultItem(),
                Weight(0)
            {}

            ResultTableNode(const ResultTableNode& src) :
                PlayFabBaseModel(),
                ResultItemType(src.ResultItemType),
                ResultItem(src.ResultItem),
                Weight(src.Weight)
            {}

            ResultTableNode(const rapidjson::Value& obj) : ResultTableNode()
            {
                readFromValue(obj);
            }

            ~ResultTableNode()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ResultItemType"); writeResultTableNodeTypeEnumJSON(ResultItemType, writer);
                writer.String("ResultItem"); writer.String(ResultItem.c_str());
                writer.String("Weight"); writer.Int(Weight);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ResultItemType_member = obj.FindMember("ResultItemType");
                if (ResultItemType_member != obj.MemberEnd() && !ResultItemType_member->value.IsNull()) ResultItemType = readResultTableNodeTypeFromValue(ResultItemType_member->value);
                const Value::ConstMemberIterator ResultItem_member = obj.FindMember("ResultItem");
                if (ResultItem_member != obj.MemberEnd() && !ResultItem_member->value.IsNull()) ResultItem = ResultItem_member->value.GetString();
                const Value::ConstMemberIterator Weight_member = obj.FindMember("Weight");
                if (Weight_member != obj.MemberEnd() && !Weight_member->value.IsNull()) Weight = Weight_member->value.GetInt();

                return true;
            }
        };

        struct RandomResultTableListing : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            Aws::String TableId;
            std::list<ResultTableNode> Nodes;

            RandomResultTableListing() :
                PlayFabBaseModel(),
                CatalogVersion(),
                TableId(),
                Nodes()
            {}

            RandomResultTableListing(const RandomResultTableListing& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                TableId(src.TableId),
                Nodes(src.Nodes)
            {}

            RandomResultTableListing(const rapidjson::Value& obj) : RandomResultTableListing()
            {
                readFromValue(obj);
            }

            ~RandomResultTableListing()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("TableId"); writer.String(TableId.c_str());
                writer.String("Nodes");
    writer.StartArray();
    for (std::list<ResultTableNode>::iterator iter = Nodes.begin(); iter != Nodes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
                if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
                const Value::ConstMemberIterator Nodes_member = obj.FindMember("Nodes");
    if (Nodes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Nodes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Nodes.push_back(ResultTableNode(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetRandomResultTablesResult : public PlayFabBaseModel
        {
            std::map<Aws::String, RandomResultTableListing> Tables;

            GetRandomResultTablesResult() :
                PlayFabBaseModel(),
                Tables()
            {}

            GetRandomResultTablesResult(const GetRandomResultTablesResult& src) :
                PlayFabBaseModel(),
                Tables(src.Tables)
            {}

            GetRandomResultTablesResult(const rapidjson::Value& obj) : GetRandomResultTablesResult()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Tables.empty()) {
    writer.String("Tables");
    writer.StartObject();
    for (std::map<Aws::String, RandomResultTableListing>::iterator iter = Tables.begin(); iter != Tables.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Tables_member = obj.FindMember("Tables");
    if (Tables_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Tables_member->value.MemberBegin(); iter != Tables_member->value.MemberEnd(); ++iter) {
            Tables[iter->name.GetString()] = RandomResultTableListing(iter->value);
        }
    }

                return true;
            }
        };

        struct GetSharedGroupDataRequest : public PlayFabBaseModel
        {
            Aws::String SharedGroupId;
            std::list<Aws::String> Keys;
            OptionalBool GetMembers;

            GetSharedGroupDataRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                Keys(),
                GetMembers()
            {}

            GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                Keys(src.Keys),
                GetMembers(src.GetMembers)
            {}

            GetSharedGroupDataRequest(const rapidjson::Value& obj) : GetSharedGroupDataRequest()
            {
                readFromValue(obj);
            }

            ~GetSharedGroupDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
                if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (GetMembers.notNull()) { writer.String("GetMembers"); writer.Bool(GetMembers); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator GetMembers_member = obj.FindMember("GetMembers");
                if (GetMembers_member != obj.MemberEnd() && !GetMembers_member->value.IsNull()) GetMembers = GetMembers_member->value.GetBool();

                return true;
            }
        };

        struct SharedGroupDataRecord : public PlayFabBaseModel
        {
            Aws::String Value;
            Aws::String LastUpdatedBy;
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;

            SharedGroupDataRecord() :
                PlayFabBaseModel(),
                Value(),
                LastUpdatedBy(),
                LastUpdated(0),
                Permission()
            {}

            SharedGroupDataRecord(const SharedGroupDataRecord& src) :
                PlayFabBaseModel(),
                Value(src.Value),
                LastUpdatedBy(src.LastUpdatedBy),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission)
            {}

            SharedGroupDataRecord(const rapidjson::Value& obj) : SharedGroupDataRecord()
            {
                readFromValue(obj);
            }

            ~SharedGroupDataRecord()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
                if (LastUpdatedBy.length() > 0) { writer.String("LastUpdatedBy"); writer.String(LastUpdatedBy.c_str()); }
                writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
                if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
                const Value::ConstMemberIterator LastUpdatedBy_member = obj.FindMember("LastUpdatedBy");
                if (LastUpdatedBy_member != obj.MemberEnd() && !LastUpdatedBy_member->value.IsNull()) LastUpdatedBy = LastUpdatedBy_member->value.GetString();
                const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
                if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct GetSharedGroupDataResult : public PlayFabBaseModel
        {
            std::map<Aws::String, SharedGroupDataRecord> Data;
            std::list<Aws::String> Members;

            GetSharedGroupDataResult() :
                PlayFabBaseModel(),
                Data(),
                Members()
            {}

            GetSharedGroupDataResult(const GetSharedGroupDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Members(src.Members)
            {}

            GetSharedGroupDataResult(const rapidjson::Value& obj) : GetSharedGroupDataResult()
            {
                readFromValue(obj);
            }

            ~GetSharedGroupDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, SharedGroupDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                if (!Members.empty()) {
    writer.String("Members");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Members.begin(); iter != Members.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = SharedGroupDataRecord(iter->value);
        }
    }
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
    if (Members_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Members_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Members.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GetTimeRequest : public PlayFabBaseModel
        {

            GetTimeRequest() :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const GetTimeRequest& src) :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const rapidjson::Value& obj) : GetTimeRequest()
            {
                readFromValue(obj);
            }

            ~GetTimeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetTimeResult : public PlayFabBaseModel
        {
            time_t Time;

            GetTimeResult() :
                PlayFabBaseModel(),
                Time(0)
            {}

            GetTimeResult(const GetTimeResult& src) :
                PlayFabBaseModel(),
                Time(src.Time)
            {}

            GetTimeResult(const rapidjson::Value& obj) : GetTimeResult()
            {
                readFromValue(obj);
            }

            ~GetTimeResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Time"); writeDatetime(Time, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Time_member = obj.FindMember("Time");
                if (Time_member != obj.MemberEnd() && !Time_member->value.IsNull()) Time = readDatetime(Time_member->value);

                return true;
            }
        };

        struct GetTitleDataRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> Keys;

            GetTitleDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetTitleDataRequest(const GetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetTitleDataRequest(const rapidjson::Value& obj) : GetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GetTitleDataResult : public PlayFabBaseModel
        {
            std::map<Aws::String, Aws::String> Data;

            GetTitleDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetTitleDataResult(const GetTitleDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetTitleDataResult(const rapidjson::Value& obj) : GetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~GetTitleDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct GetTitleNewsRequest : public PlayFabBaseModel
        {
            OptionalInt32 Count;

            GetTitleNewsRequest() :
                PlayFabBaseModel(),
                Count()
            {}

            GetTitleNewsRequest(const GetTitleNewsRequest& src) :
                PlayFabBaseModel(),
                Count(src.Count)
            {}

            GetTitleNewsRequest(const rapidjson::Value& obj) : GetTitleNewsRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Count.notNull()) { writer.String("Count"); writer.Int(Count); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Count_member = obj.FindMember("Count");
                if (Count_member != obj.MemberEnd() && !Count_member->value.IsNull()) Count = Count_member->value.GetInt();

                return true;
            }
        };

        struct TitleNewsItem : public PlayFabBaseModel
        {
            time_t Timestamp;
            Aws::String NewsId;
            Aws::String Title;
            Aws::String Body;

            TitleNewsItem() :
                PlayFabBaseModel(),
                Timestamp(0),
                NewsId(),
                Title(),
                Body()
            {}

            TitleNewsItem(const TitleNewsItem& src) :
                PlayFabBaseModel(),
                Timestamp(src.Timestamp),
                NewsId(src.NewsId),
                Title(src.Title),
                Body(src.Body)
            {}

            TitleNewsItem(const rapidjson::Value& obj) : TitleNewsItem()
            {
                readFromValue(obj);
            }

            ~TitleNewsItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Timestamp"); writeDatetime(Timestamp, writer);
                if (NewsId.length() > 0) { writer.String("NewsId"); writer.String(NewsId.c_str()); }
                if (Title.length() > 0) { writer.String("Title"); writer.String(Title.c_str()); }
                if (Body.length() > 0) { writer.String("Body"); writer.String(Body.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator NewsId_member = obj.FindMember("NewsId");
                if (NewsId_member != obj.MemberEnd() && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();
                const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
                if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd() && !Body_member->value.IsNull()) Body = Body_member->value.GetString();

                return true;
            }
        };

        struct GetTitleNewsResult : public PlayFabBaseModel
        {
            std::list<TitleNewsItem> News;

            GetTitleNewsResult() :
                PlayFabBaseModel(),
                News()
            {}

            GetTitleNewsResult(const GetTitleNewsResult& src) :
                PlayFabBaseModel(),
                News(src.News)
            {}

            GetTitleNewsResult(const rapidjson::Value& obj) : GetTitleNewsResult()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!News.empty()) {
    writer.String("News");
    writer.StartArray();
    for (std::list<TitleNewsItem>::iterator iter = News.begin(); iter != News.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator News_member = obj.FindMember("News");
    if (News_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = News_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            News.push_back(TitleNewsItem(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetUserAccountInfoRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;

            GetUserAccountInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserAccountInfoRequest(const GetUserAccountInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetUserAccountInfoRequest(const rapidjson::Value& obj) : GetUserAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetUserAccountInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetUserAccountInfoResult : public PlayFabBaseModel
        {
            UserAccountInfo* UserInfo;

            GetUserAccountInfoResult() :
                PlayFabBaseModel(),
                UserInfo(nullptr)
            {}

            GetUserAccountInfoResult(const GetUserAccountInfoResult& src) :
                PlayFabBaseModel(),
                UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : nullptr)
            {}

            GetUserAccountInfoResult(const rapidjson::Value& obj) : GetUserAccountInfoResult()
            {
                readFromValue(obj);
            }

            ~GetUserAccountInfoResult()
            {
                if (UserInfo != nullptr) delete UserInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UserInfo != nullptr) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
                if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

                return true;
            }
        };

        struct GetUserBansRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;

            GetUserBansRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserBansRequest(const GetUserBansRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetUserBansRequest(const rapidjson::Value& obj) : GetUserBansRequest()
            {
                readFromValue(obj);
            }

            ~GetUserBansRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetUserBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            GetUserBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            GetUserBansResult(const GetUserBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            GetUserBansResult(const rapidjson::Value& obj) : GetUserBansResult()
            {
                readFromValue(obj);
            }

            ~GetUserBansResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GetUserDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::list<Aws::String> Keys;
            OptionalUint32 IfChangedFromDataVersion;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Keys(),
                IfChangedFromDataVersion()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Keys(src.Keys),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion)
            {}

            GetUserDataRequest(const rapidjson::Value& obj) : GetUserDataRequest()
            {
                readFromValue(obj);
            }

            ~GetUserDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Uint(IfChangedFromDataVersion); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
                if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();

                return true;
            }
        };

        struct GetUserDataResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Uint32 DataVersion;
            std::map<Aws::String, UserDataRecord> Data;

            GetUserDataResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                DataVersion(0),
                Data()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DataVersion(src.DataVersion),
                Data(src.Data)
            {}

            GetUserDataResult(const rapidjson::Value& obj) : GetUserDataResult()
            {
                readFromValue(obj);
            }

            ~GetUserDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                writer.String("DataVersion"); writer.Uint(DataVersion);
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }

                return true;
            }
        };

        struct GetUserInventoryRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;

            GetUserInventoryRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetUserInventoryRequest(const rapidjson::Value& obj) : GetUserInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::list<ItemInstance> Inventory;
            std::map<Aws::String, Int32> VirtualCurrency;
            std::map<Aws::String, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetUserInventoryResult(const rapidjson::Value& obj) : GetUserInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (!Inventory.empty()) {
    writer.String("Inventory");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!VirtualCurrency.empty()) {
    writer.String("VirtualCurrency");
    writer.StartObject();
    for (std::map<Aws::String, Int32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
                if (!VirtualCurrencyRechargeTimes.empty()) {
    writer.String("VirtualCurrencyRechargeTimes");
    writer.StartObject();
    for (std::map<Aws::String, VirtualCurrencyRechargeTime>::iterator iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }
                const Value::ConstMemberIterator VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
    if (VirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != VirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
        }
    }

                return true;
            }
        };

        struct GrantCharacterToUserRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterName;
            Aws::String CharacterType;

            GrantCharacterToUserRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterName(),
                CharacterType()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType)
            {}

            GrantCharacterToUserRequest(const rapidjson::Value& obj) : GrantCharacterToUserRequest()
            {
                readFromValue(obj);
            }

            ~GrantCharacterToUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterName"); writer.String(CharacterName.c_str());
                writer.String("CharacterType"); writer.String(CharacterType.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();

                return true;
            }
        };

        struct GrantCharacterToUserResult : public PlayFabBaseModel
        {
            Aws::String CharacterId;

            GrantCharacterToUserResult() :
                PlayFabBaseModel(),
                CharacterId()
            {}

            GrantCharacterToUserResult(const GrantCharacterToUserResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId)
            {}

            GrantCharacterToUserResult(const rapidjson::Value& obj) : GrantCharacterToUserResult()
            {
                readFromValue(obj);
            }

            ~GrantCharacterToUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct GrantedItemInstance : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            bool Result;
            Aws::String ItemId;
            Aws::String ItemInstanceId;
            Aws::String ItemClass;
            OptionalTime PurchaseDate;
            OptionalTime Expiration;
            OptionalInt32 RemainingUses;
            OptionalInt32 UsesIncrementedBy;
            Aws::String Annotation;
            Aws::String CatalogVersion;
            Aws::String BundleParent;
            Aws::String DisplayName;
            Aws::String UnitCurrency;
            Uint32 UnitPrice;
            std::list<Aws::String> BundleContents;
            std::map<Aws::String, Aws::String> CustomData;

            GrantedItemInstance() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Result(false),
                ItemId(),
                ItemInstanceId(),
                ItemClass(),
                PurchaseDate(),
                Expiration(),
                RemainingUses(),
                UsesIncrementedBy(),
                Annotation(),
                CatalogVersion(),
                BundleParent(),
                DisplayName(),
                UnitCurrency(),
                UnitPrice(0),
                BundleContents(),
                CustomData()
            {}

            GrantedItemInstance(const GrantedItemInstance& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Result(src.Result),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                ItemClass(src.ItemClass),
                PurchaseDate(src.PurchaseDate),
                Expiration(src.Expiration),
                RemainingUses(src.RemainingUses),
                UsesIncrementedBy(src.UsesIncrementedBy),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                BundleParent(src.BundleParent),
                DisplayName(src.DisplayName),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                BundleContents(src.BundleContents),
                CustomData(src.CustomData)
            {}

            GrantedItemInstance(const rapidjson::Value& obj) : GrantedItemInstance()
            {
                readFromValue(obj);
            }

            ~GrantedItemInstance()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.String("Result"); writer.Bool(Result);
                if (ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
                if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
                if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
                if (PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
                if (Expiration.notNull()) { writer.String("Expiration"); writeDatetime(Expiration, writer); }
                if (RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
                if (UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
                if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                if (BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
                if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
                if (UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
                writer.String("UnitPrice"); writer.Uint(UnitPrice);
                if (!BundleContents.empty()) {
    writer.String("BundleContents");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (!CustomData.empty()) {
    writer.String("CustomData");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
                if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
                const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
                if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
                const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
                if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator BundleParent_member = obj.FindMember("BundleParent");
                if (BundleParent_member != obj.MemberEnd() && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
                if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
                const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
                if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
                const Value::ConstMemberIterator BundleContents_member = obj.FindMember("BundleContents");
    if (BundleContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundleContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundleContents.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
            CustomData[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct GrantItemsToCharacterRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            Aws::String CharacterId;
            Aws::String PlayFabId;
            Aws::String Annotation;
            std::list<Aws::String> ItemIds;

            GrantItemsToCharacterRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                PlayFabId(),
                Annotation(),
                ItemIds()
            {}

            GrantItemsToCharacterRequest(const GrantItemsToCharacterRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId),
                Annotation(src.Annotation),
                ItemIds(src.ItemIds)
            {}

            GrantItemsToCharacterRequest(const rapidjson::Value& obj) : GrantItemsToCharacterRequest()
            {
                readFromValue(obj);
            }

            ~GrantItemsToCharacterRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
                if (!ItemIds.empty()) {
    writer.String("ItemIds");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = ItemIds.begin(); iter != ItemIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator ItemIds_member = obj.FindMember("ItemIds");
    if (ItemIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemIds.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GrantItemsToCharacterResult : public PlayFabBaseModel
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToCharacterResult() :
                PlayFabBaseModel(),
                ItemGrantResults()
            {}

            GrantItemsToCharacterResult(const GrantItemsToCharacterResult& src) :
                PlayFabBaseModel(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            GrantItemsToCharacterResult(const rapidjson::Value& obj) : GrantItemsToCharacterResult()
            {
                readFromValue(obj);
            }

            ~GrantItemsToCharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!ItemGrantResults.empty()) {
    writer.String("ItemGrantResults");
    writer.StartArray();
    for (std::list<GrantedItemInstance>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemGrantResults_member = obj.FindMember("ItemGrantResults");
    if (ItemGrantResults_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemGrantResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemGrantResults.push_back(GrantedItemInstance(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GrantItemsToUserRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            Aws::String PlayFabId;
            Aws::String Annotation;
            std::list<Aws::String> ItemIds;

            GrantItemsToUserRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                PlayFabId(),
                Annotation(),
                ItemIds()
            {}

            GrantItemsToUserRequest(const GrantItemsToUserRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                PlayFabId(src.PlayFabId),
                Annotation(src.Annotation),
                ItemIds(src.ItemIds)
            {}

            GrantItemsToUserRequest(const rapidjson::Value& obj) : GrantItemsToUserRequest()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
                writer.String("ItemIds");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = ItemIds.begin(); iter != ItemIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator ItemIds_member = obj.FindMember("ItemIds");
    if (ItemIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemIds.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GrantItemsToUserResult : public PlayFabBaseModel
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToUserResult() :
                PlayFabBaseModel(),
                ItemGrantResults()
            {}

            GrantItemsToUserResult(const GrantItemsToUserResult& src) :
                PlayFabBaseModel(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            GrantItemsToUserResult(const rapidjson::Value& obj) : GrantItemsToUserResult()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!ItemGrantResults.empty()) {
    writer.String("ItemGrantResults");
    writer.StartArray();
    for (std::list<GrantedItemInstance>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemGrantResults_member = obj.FindMember("ItemGrantResults");
    if (ItemGrantResults_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemGrantResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemGrantResults.push_back(GrantedItemInstance(memberList[i]));
        }
    }

                return true;
            }
        };

        struct ItemGrant : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String ItemId;
            Aws::String Annotation;
            Aws::String CharacterId;
            std::map<Aws::String, Aws::String> Data;
            std::list<Aws::String> KeysToRemove;

            ItemGrant() :
                PlayFabBaseModel(),
                PlayFabId(),
                ItemId(),
                Annotation(),
                CharacterId(),
                Data(),
                KeysToRemove()
            {}

            ItemGrant(const ItemGrant& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ItemId(src.ItemId),
                Annotation(src.Annotation),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove)
            {}

            ItemGrant(const rapidjson::Value& obj) : ItemGrant()
            {
                readFromValue(obj);
            }

            ~ItemGrant()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("ItemId"); writer.String(ItemId.c_str());
                if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct GrantItemsToUsersRequest : public PlayFabBaseModel
        {
            Aws::String CatalogVersion;
            std::list<ItemGrant> ItemGrants;

            GrantItemsToUsersRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                ItemGrants()
            {}

            GrantItemsToUsersRequest(const GrantItemsToUsersRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                ItemGrants(src.ItemGrants)
            {}

            GrantItemsToUsersRequest(const rapidjson::Value& obj) : GrantItemsToUsersRequest()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.String("ItemGrants");
    writer.StartArray();
    for (std::list<ItemGrant>::iterator iter = ItemGrants.begin(); iter != ItemGrants.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator ItemGrants_member = obj.FindMember("ItemGrants");
    if (ItemGrants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemGrants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemGrants.push_back(ItemGrant(memberList[i]));
        }
    }

                return true;
            }
        };

        struct GrantItemsToUsersResult : public PlayFabBaseModel
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToUsersResult() :
                PlayFabBaseModel(),
                ItemGrantResults()
            {}

            GrantItemsToUsersResult(const GrantItemsToUsersResult& src) :
                PlayFabBaseModel(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            GrantItemsToUsersResult(const rapidjson::Value& obj) : GrantItemsToUsersResult()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUsersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!ItemGrantResults.empty()) {
    writer.String("ItemGrantResults");
    writer.StartArray();
    for (std::list<GrantedItemInstance>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemGrantResults_member = obj.FindMember("ItemGrantResults");
    if (ItemGrantResults_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemGrantResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemGrantResults.push_back(GrantedItemInstance(memberList[i]));
        }
    }

                return true;
            }
        };

        struct ListUsersCharactersRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;

            ListUsersCharactersRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            ListUsersCharactersRequest(const ListUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            ListUsersCharactersRequest(const rapidjson::Value& obj) : ListUsersCharactersRequest()
            {
                readFromValue(obj);
            }

            ~ListUsersCharactersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct ListUsersCharactersResult : public PlayFabBaseModel
        {
            std::list<CharacterResult> Characters;

            ListUsersCharactersResult() :
                PlayFabBaseModel(),
                Characters()
            {}

            ListUsersCharactersResult(const ListUsersCharactersResult& src) :
                PlayFabBaseModel(),
                Characters(src.Characters)
            {}

            ListUsersCharactersResult(const rapidjson::Value& obj) : ListUsersCharactersResult()
            {
                readFromValue(obj);
            }

            ~ListUsersCharactersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Characters.empty()) {
    writer.String("Characters");
    writer.StartArray();
    for (std::list<CharacterResult>::iterator iter = Characters.begin(); iter != Characters.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Characters_member = obj.FindMember("Characters");
    if (Characters_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Characters_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Characters.push_back(CharacterResult(memberList[i]));
        }
    }

                return true;
            }
        };

        struct ModifyCharacterVirtualCurrencyResult : public PlayFabBaseModel
        {
            Aws::String VirtualCurrency;
            Int32 Balance;

            ModifyCharacterVirtualCurrencyResult() :
                PlayFabBaseModel(),
                VirtualCurrency(),
                Balance(0)
            {}

            ModifyCharacterVirtualCurrencyResult(const ModifyCharacterVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                VirtualCurrency(src.VirtualCurrency),
                Balance(src.Balance)
            {}

            ModifyCharacterVirtualCurrencyResult(const rapidjson::Value& obj) : ModifyCharacterVirtualCurrencyResult()
            {
                readFromValue(obj);
            }

            ~ModifyCharacterVirtualCurrencyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
                writer.String("Balance"); writer.Int(Balance);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
                if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();

                return true;
            }
        };

        struct ModifyItemUsesRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String ItemInstanceId;
            Int32 UsesToAdd;

            ModifyItemUsesRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                ItemInstanceId(),
                UsesToAdd(0)
            {}

            ModifyItemUsesRequest(const ModifyItemUsesRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ItemInstanceId(src.ItemInstanceId),
                UsesToAdd(src.UsesToAdd)
            {}

            ModifyItemUsesRequest(const rapidjson::Value& obj) : ModifyItemUsesRequest()
            {
                readFromValue(obj);
            }

            ~ModifyItemUsesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
                writer.String("UsesToAdd"); writer.Int(UsesToAdd);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator UsesToAdd_member = obj.FindMember("UsesToAdd");
                if (UsesToAdd_member != obj.MemberEnd() && !UsesToAdd_member->value.IsNull()) UsesToAdd = UsesToAdd_member->value.GetInt();

                return true;
            }
        };

        struct ModifyItemUsesResult : public PlayFabBaseModel
        {
            Aws::String ItemInstanceId;
            Int32 RemainingUses;

            ModifyItemUsesResult() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                RemainingUses(0)
            {}

            ModifyItemUsesResult(const ModifyItemUsesResult& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ModifyItemUsesResult(const rapidjson::Value& obj) : ModifyItemUsesResult()
            {
                readFromValue(obj);
            }

            ~ModifyItemUsesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
                writer.String("RemainingUses"); writer.Int(RemainingUses);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();

                return true;
            }
        };

        struct ModifyUserVirtualCurrencyResult : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String VirtualCurrency;
            Int32 BalanceChange;
            Int32 Balance;

            ModifyUserVirtualCurrencyResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                BalanceChange(0),
                Balance(0)
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                BalanceChange(src.BalanceChange),
                Balance(src.Balance)
            {}

            ModifyUserVirtualCurrencyResult(const rapidjson::Value& obj) : ModifyUserVirtualCurrencyResult()
            {
                readFromValue(obj);
            }

            ~ModifyUserVirtualCurrencyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
                if (VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
                writer.String("BalanceChange"); writer.Int(BalanceChange);
                writer.String("Balance"); writer.Int(Balance);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator BalanceChange_member = obj.FindMember("BalanceChange");
                if (BalanceChange_member != obj.MemberEnd() && !BalanceChange_member->value.IsNull()) BalanceChange = BalanceChange_member->value.GetInt();
                const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
                if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();

                return true;
            }
        };

        struct MoveItemToCharacterFromCharacterRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String GivingCharacterId;
            Aws::String ReceivingCharacterId;
            Aws::String ItemInstanceId;

            MoveItemToCharacterFromCharacterRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                GivingCharacterId(),
                ReceivingCharacterId(),
                ItemInstanceId()
            {}

            MoveItemToCharacterFromCharacterRequest(const MoveItemToCharacterFromCharacterRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                GivingCharacterId(src.GivingCharacterId),
                ReceivingCharacterId(src.ReceivingCharacterId),
                ItemInstanceId(src.ItemInstanceId)
            {}

            MoveItemToCharacterFromCharacterRequest(const rapidjson::Value& obj) : MoveItemToCharacterFromCharacterRequest()
            {
                readFromValue(obj);
            }

            ~MoveItemToCharacterFromCharacterRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("GivingCharacterId"); writer.String(GivingCharacterId.c_str());
                writer.String("ReceivingCharacterId"); writer.String(ReceivingCharacterId.c_str());
                writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator GivingCharacterId_member = obj.FindMember("GivingCharacterId");
                if (GivingCharacterId_member != obj.MemberEnd() && !GivingCharacterId_member->value.IsNull()) GivingCharacterId = GivingCharacterId_member->value.GetString();
                const Value::ConstMemberIterator ReceivingCharacterId_member = obj.FindMember("ReceivingCharacterId");
                if (ReceivingCharacterId_member != obj.MemberEnd() && !ReceivingCharacterId_member->value.IsNull()) ReceivingCharacterId = ReceivingCharacterId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

                return true;
            }
        };

        struct MoveItemToCharacterFromCharacterResult : public PlayFabBaseModel
        {

            MoveItemToCharacterFromCharacterResult() :
                PlayFabBaseModel()
            {}

            MoveItemToCharacterFromCharacterResult(const MoveItemToCharacterFromCharacterResult& src) :
                PlayFabBaseModel()
            {}

            MoveItemToCharacterFromCharacterResult(const rapidjson::Value& obj) : MoveItemToCharacterFromCharacterResult()
            {
                readFromValue(obj);
            }

            ~MoveItemToCharacterFromCharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct MoveItemToCharacterFromUserRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String ItemInstanceId;

            MoveItemToCharacterFromUserRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ItemInstanceId()
            {}

            MoveItemToCharacterFromUserRequest(const MoveItemToCharacterFromUserRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId)
            {}

            MoveItemToCharacterFromUserRequest(const rapidjson::Value& obj) : MoveItemToCharacterFromUserRequest()
            {
                readFromValue(obj);
            }

            ~MoveItemToCharacterFromUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

                return true;
            }
        };

        struct MoveItemToCharacterFromUserResult : public PlayFabBaseModel
        {

            MoveItemToCharacterFromUserResult() :
                PlayFabBaseModel()
            {}

            MoveItemToCharacterFromUserResult(const MoveItemToCharacterFromUserResult& src) :
                PlayFabBaseModel()
            {}

            MoveItemToCharacterFromUserResult(const rapidjson::Value& obj) : MoveItemToCharacterFromUserResult()
            {
                readFromValue(obj);
            }

            ~MoveItemToCharacterFromUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct MoveItemToUserFromCharacterRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String ItemInstanceId;

            MoveItemToUserFromCharacterRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ItemInstanceId()
            {}

            MoveItemToUserFromCharacterRequest(const MoveItemToUserFromCharacterRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId)
            {}

            MoveItemToUserFromCharacterRequest(const rapidjson::Value& obj) : MoveItemToUserFromCharacterRequest()
            {
                readFromValue(obj);
            }

            ~MoveItemToUserFromCharacterRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

                return true;
            }
        };

        struct MoveItemToUserFromCharacterResult : public PlayFabBaseModel
        {

            MoveItemToUserFromCharacterResult() :
                PlayFabBaseModel()
            {}

            MoveItemToUserFromCharacterResult(const MoveItemToUserFromCharacterResult& src) :
                PlayFabBaseModel()
            {}

            MoveItemToUserFromCharacterResult(const rapidjson::Value& obj) : MoveItemToUserFromCharacterResult()
            {
                readFromValue(obj);
            }

            ~MoveItemToUserFromCharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct NotifyMatchmakerPlayerLeftRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;
            Aws::String PlayFabId;

            NotifyMatchmakerPlayerLeftRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                PlayFabId()
            {}

            NotifyMatchmakerPlayerLeftRequest(const NotifyMatchmakerPlayerLeftRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            NotifyMatchmakerPlayerLeftRequest(const rapidjson::Value& obj) : NotifyMatchmakerPlayerLeftRequest()
            {
                readFromValue(obj);
            }

            ~NotifyMatchmakerPlayerLeftRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        enum PlayerConnectionState
        {
            PlayerConnectionStateUnassigned,
            PlayerConnectionStateConnecting,
            PlayerConnectionStateParticipating,
            PlayerConnectionStateParticipated
        };

        inline void writePlayerConnectionStateEnumJSON(PlayerConnectionState enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case PlayerConnectionStateUnassigned: writer.String("Unassigned"); break;
            case PlayerConnectionStateConnecting: writer.String("Connecting"); break;
            case PlayerConnectionStateParticipating: writer.String("Participating"); break;
            case PlayerConnectionStateParticipated: writer.String("Participated"); break;

            }
        }

        inline PlayerConnectionState readPlayerConnectionStateFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, PlayerConnectionState> _PlayerConnectionStateMap;
            if (_PlayerConnectionStateMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _PlayerConnectionStateMap["Unassigned"] = PlayerConnectionStateUnassigned;
                _PlayerConnectionStateMap["Connecting"] = PlayerConnectionStateConnecting;
                _PlayerConnectionStateMap["Participating"] = PlayerConnectionStateParticipating;
                _PlayerConnectionStateMap["Participated"] = PlayerConnectionStateParticipated;

            }

            auto output = _PlayerConnectionStateMap.find(obj.GetString());
            if (output != _PlayerConnectionStateMap.end())
                return output->second;

            return PlayerConnectionStateUnassigned; // Basically critical fail
        }

        struct NotifyMatchmakerPlayerLeftResult : public PlayFabBaseModel
        {
            Boxed<PlayerConnectionState> PlayerState;

            NotifyMatchmakerPlayerLeftResult() :
                PlayFabBaseModel(),
                PlayerState()
            {}

            NotifyMatchmakerPlayerLeftResult(const NotifyMatchmakerPlayerLeftResult& src) :
                PlayFabBaseModel(),
                PlayerState(src.PlayerState)
            {}

            NotifyMatchmakerPlayerLeftResult(const rapidjson::Value& obj) : NotifyMatchmakerPlayerLeftResult()
            {
                readFromValue(obj);
            }

            ~NotifyMatchmakerPlayerLeftResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayerState.notNull()) { writer.String("PlayerState"); writePlayerConnectionStateEnumJSON(PlayerState, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerState_member = obj.FindMember("PlayerState");
                if (PlayerState_member != obj.MemberEnd() && !PlayerState_member->value.IsNull()) PlayerState = readPlayerConnectionStateFromValue(PlayerState_member->value);

                return true;
            }
        };

        struct RedeemCouponRequest : public PlayFabBaseModel
        {
            Aws::String CouponCode;
            Aws::String PlayFabId;
            Aws::String CatalogVersion;
            Aws::String CharacterId;

            RedeemCouponRequest() :
                PlayFabBaseModel(),
                CouponCode(),
                PlayFabId(),
                CatalogVersion(),
                CharacterId()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabBaseModel(),
                CouponCode(src.CouponCode),
                PlayFabId(src.PlayFabId),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId)
            {}

            RedeemCouponRequest(const rapidjson::Value& obj) : RedeemCouponRequest()
            {
                readFromValue(obj);
            }

            ~RedeemCouponRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CouponCode"); writer.String(CouponCode.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CouponCode_member = obj.FindMember("CouponCode");
                if (CouponCode_member != obj.MemberEnd() && !CouponCode_member->value.IsNull()) CouponCode = CouponCode_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct RedeemCouponResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> GrantedItems;

            RedeemCouponResult() :
                PlayFabBaseModel(),
                GrantedItems()
            {}

            RedeemCouponResult(const RedeemCouponResult& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems)
            {}

            RedeemCouponResult(const rapidjson::Value& obj) : RedeemCouponResult()
            {
                readFromValue(obj);
            }

            ~RedeemCouponResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!GrantedItems.empty()) {
    writer.String("GrantedItems");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = GrantedItems.begin(); iter != GrantedItems.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
    if (GrantedItems_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GrantedItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GrantedItems.push_back(ItemInstance(memberList[i]));
        }
    }

                return true;
            }
        };

        struct RedeemMatchmakerTicketRequest : public PlayFabBaseModel
        {
            Aws::String Ticket;
            Aws::String LobbyId;

            RedeemMatchmakerTicketRequest() :
                PlayFabBaseModel(),
                Ticket(),
                LobbyId()
            {}

            RedeemMatchmakerTicketRequest(const RedeemMatchmakerTicketRequest& src) :
                PlayFabBaseModel(),
                Ticket(src.Ticket),
                LobbyId(src.LobbyId)
            {}

            RedeemMatchmakerTicketRequest(const rapidjson::Value& obj) : RedeemMatchmakerTicketRequest()
            {
                readFromValue(obj);
            }

            ~RedeemMatchmakerTicketRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Ticket"); writer.String(Ticket.c_str());
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Ticket_member = obj.FindMember("Ticket");
                if (Ticket_member != obj.MemberEnd() && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

                return true;
            }
        };

        struct RedeemMatchmakerTicketResult : public PlayFabBaseModel
        {
            bool TicketIsValid;
            Aws::String Error;
            UserAccountInfo* UserInfo;

            RedeemMatchmakerTicketResult() :
                PlayFabBaseModel(),
                TicketIsValid(false),
                Error(),
                UserInfo(nullptr)
            {}

            RedeemMatchmakerTicketResult(const RedeemMatchmakerTicketResult& src) :
                PlayFabBaseModel(),
                TicketIsValid(src.TicketIsValid),
                Error(src.Error),
                UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : nullptr)
            {}

            RedeemMatchmakerTicketResult(const rapidjson::Value& obj) : RedeemMatchmakerTicketResult()
            {
                readFromValue(obj);
            }

            ~RedeemMatchmakerTicketResult()
            {
                if (UserInfo != nullptr) delete UserInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TicketIsValid"); writer.Bool(TicketIsValid);
                if (Error.length() > 0) { writer.String("Error"); writer.String(Error.c_str()); }
                if (UserInfo != nullptr) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TicketIsValid_member = obj.FindMember("TicketIsValid");
                if (TicketIsValid_member != obj.MemberEnd() && !TicketIsValid_member->value.IsNull()) TicketIsValid = TicketIsValid_member->value.GetBool();
                const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
                if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
                const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
                if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

                return true;
            }
        };

        struct RefreshGameServerInstanceHeartbeatRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;

            RefreshGameServerInstanceHeartbeatRequest() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            RefreshGameServerInstanceHeartbeatRequest(const RefreshGameServerInstanceHeartbeatRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            RefreshGameServerInstanceHeartbeatRequest(const rapidjson::Value& obj) : RefreshGameServerInstanceHeartbeatRequest()
            {
                readFromValue(obj);
            }

            ~RefreshGameServerInstanceHeartbeatRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

                return true;
            }
        };

        struct RefreshGameServerInstanceHeartbeatResult : public PlayFabBaseModel
        {

            RefreshGameServerInstanceHeartbeatResult() :
                PlayFabBaseModel()
            {}

            RefreshGameServerInstanceHeartbeatResult(const RefreshGameServerInstanceHeartbeatResult& src) :
                PlayFabBaseModel()
            {}

            RefreshGameServerInstanceHeartbeatResult(const rapidjson::Value& obj) : RefreshGameServerInstanceHeartbeatResult()
            {
                readFromValue(obj);
            }

            ~RefreshGameServerInstanceHeartbeatResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        enum Region
        {
            RegionUSCentral,
            RegionUSEast,
            RegionEUWest,
            RegionSingapore,
            RegionJapan,
            RegionBrazil,
            RegionAustralia
        };

        inline void writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case RegionUSCentral: writer.String("USCentral"); break;
            case RegionUSEast: writer.String("USEast"); break;
            case RegionEUWest: writer.String("EUWest"); break;
            case RegionSingapore: writer.String("Singapore"); break;
            case RegionJapan: writer.String("Japan"); break;
            case RegionBrazil: writer.String("Brazil"); break;
            case RegionAustralia: writer.String("Australia"); break;

            }
        }

        inline Region readRegionFromValue(const rapidjson::Value& obj)
        {
            static std::map<Aws::String, Region> _RegionMap;
            if (_RegionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _RegionMap["USCentral"] = RegionUSCentral;
                _RegionMap["USEast"] = RegionUSEast;
                _RegionMap["EUWest"] = RegionEUWest;
                _RegionMap["Singapore"] = RegionSingapore;
                _RegionMap["Japan"] = RegionJapan;
                _RegionMap["Brazil"] = RegionBrazil;
                _RegionMap["Australia"] = RegionAustralia;

            }

            auto output = _RegionMap.find(obj.GetString());
            if (output != _RegionMap.end())
                return output->second;

            return RegionUSCentral; // Basically critical fail
        }

        struct RegisterGameRequest : public PlayFabBaseModel
        {
            Aws::String ServerHost;
            Aws::String ServerPort;
            Aws::String Build;
            Region pfRegion;
            Aws::String GameMode;
            std::map<Aws::String, Aws::String> Tags;

            RegisterGameRequest() :
                PlayFabBaseModel(),
                ServerHost(),
                ServerPort(),
                Build(),
                pfRegion(),
                GameMode(),
                Tags()
            {}

            RegisterGameRequest(const RegisterGameRequest& src) :
                PlayFabBaseModel(),
                ServerHost(src.ServerHost),
                ServerPort(src.ServerPort),
                Build(src.Build),
                pfRegion(src.pfRegion),
                GameMode(src.GameMode),
                Tags(src.Tags)
            {}

            RegisterGameRequest(const rapidjson::Value& obj) : RegisterGameRequest()
            {
                readFromValue(obj);
            }

            ~RegisterGameRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ServerHost"); writer.String(ServerHost.c_str());
                writer.String("ServerPort"); writer.String(ServerPort.c_str());
                writer.String("Build"); writer.String(Build.c_str());
                writer.String("Region"); writeRegionEnumJSON(pfRegion, writer);
                writer.String("GameMode"); writer.String(GameMode.c_str());
                if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Tags.begin(); iter != Tags.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ServerHost_member = obj.FindMember("ServerHost");
                if (ServerHost_member != obj.MemberEnd() && !ServerHost_member->value.IsNull()) ServerHost = ServerHost_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetString();
                const Value::ConstMemberIterator Build_member = obj.FindMember("Build");
                if (Build_member != obj.MemberEnd() && !Build_member->value.IsNull()) Build = Build_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Tags_member->value.MemberBegin(); iter != Tags_member->value.MemberEnd(); ++iter) {
            Tags[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct RegisterGameResponse : public PlayFabBaseModel
        {
            Aws::String LobbyId;

            RegisterGameResponse() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            RegisterGameResponse(const RegisterGameResponse& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            RegisterGameResponse(const rapidjson::Value& obj) : RegisterGameResponse()
            {
                readFromValue(obj);
            }

            ~RegisterGameResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (LobbyId.length() > 0) { writer.String("LobbyId"); writer.String(LobbyId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

                return true;
            }
        };

        struct RemoveFriendRequest : public PlayFabBaseModel
        {
            Aws::String FriendPlayFabId;
            Aws::String PlayFabId;

            RemoveFriendRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                PlayFabId()
            {}

            RemoveFriendRequest(const RemoveFriendRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                PlayFabId(src.PlayFabId)
            {}

            RemoveFriendRequest(const rapidjson::Value& obj) : RemoveFriendRequest()
            {
                readFromValue(obj);
            }

            ~RemoveFriendRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str());
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct RemovePlayerTagRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String TagName;

            RemovePlayerTagRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                TagName()
            {}

            RemovePlayerTagRequest(const RemovePlayerTagRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            RemovePlayerTagRequest(const rapidjson::Value& obj) : RemovePlayerTagRequest()
            {
                readFromValue(obj);
            }

            ~RemovePlayerTagRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("TagName"); writer.String(TagName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator TagName_member = obj.FindMember("TagName");
                if (TagName_member != obj.MemberEnd() && !TagName_member->value.IsNull()) TagName = TagName_member->value.GetString();

                return true;
            }
        };

        struct RemovePlayerTagResult : public PlayFabBaseModel
        {

            RemovePlayerTagResult() :
                PlayFabBaseModel()
            {}

            RemovePlayerTagResult(const RemovePlayerTagResult& src) :
                PlayFabBaseModel()
            {}

            RemovePlayerTagResult(const rapidjson::Value& obj) : RemovePlayerTagResult()
            {
                readFromValue(obj);
            }

            ~RemovePlayerTagResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RemoveSharedGroupMembersRequest : public PlayFabBaseModel
        {
            Aws::String SharedGroupId;
            std::list<Aws::String> PlayFabIds;

            RemoveSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                PlayFabIds()
            {}

            RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                PlayFabIds(src.PlayFabIds)
            {}

            RemoveSharedGroupMembersRequest(const rapidjson::Value& obj) : RemoveSharedGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~RemoveSharedGroupMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
                writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct RemoveSharedGroupMembersResult : public PlayFabBaseModel
        {

            RemoveSharedGroupMembersResult() :
                PlayFabBaseModel()
            {}

            RemoveSharedGroupMembersResult(const RemoveSharedGroupMembersResult& src) :
                PlayFabBaseModel()
            {}

            RemoveSharedGroupMembersResult(const rapidjson::Value& obj) : RemoveSharedGroupMembersResult()
            {
                readFromValue(obj);
            }

            ~RemoveSharedGroupMembersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ReportPlayerServerRequest : public PlayFabBaseModel
        {
            Aws::String ReporterId;
            Aws::String ReporteeId;
            Aws::String Comment;

            ReportPlayerServerRequest() :
                PlayFabBaseModel(),
                ReporterId(),
                ReporteeId(),
                Comment()
            {}

            ReportPlayerServerRequest(const ReportPlayerServerRequest& src) :
                PlayFabBaseModel(),
                ReporterId(src.ReporterId),
                ReporteeId(src.ReporteeId),
                Comment(src.Comment)
            {}

            ReportPlayerServerRequest(const rapidjson::Value& obj) : ReportPlayerServerRequest()
            {
                readFromValue(obj);
            }

            ~ReportPlayerServerRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ReporterId"); writer.String(ReporterId.c_str());
                writer.String("ReporteeId"); writer.String(ReporteeId.c_str());
                if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReporterId_member = obj.FindMember("ReporterId");
                if (ReporterId_member != obj.MemberEnd() && !ReporterId_member->value.IsNull()) ReporterId = ReporterId_member->value.GetString();
                const Value::ConstMemberIterator ReporteeId_member = obj.FindMember("ReporteeId");
                if (ReporteeId_member != obj.MemberEnd() && !ReporteeId_member->value.IsNull()) ReporteeId = ReporteeId_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();

                return true;
            }
        };

        struct ReportPlayerServerResult : public PlayFabBaseModel
        {
            OptionalBool Updated;
            Int32 SubmissionsRemaining;

            ReportPlayerServerResult() :
                PlayFabBaseModel(),
                Updated(),
                SubmissionsRemaining(0)
            {}

            ReportPlayerServerResult(const ReportPlayerServerResult& src) :
                PlayFabBaseModel(),
                Updated(src.Updated),
                SubmissionsRemaining(src.SubmissionsRemaining)
            {}

            ReportPlayerServerResult(const rapidjson::Value& obj) : ReportPlayerServerResult()
            {
                readFromValue(obj);
            }

            ~ReportPlayerServerResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Updated.notNull()) { writer.String("Updated"); writer.Bool(Updated); }
                writer.String("SubmissionsRemaining"); writer.Int(SubmissionsRemaining);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Updated_member = obj.FindMember("Updated");
                if (Updated_member != obj.MemberEnd() && !Updated_member->value.IsNull()) Updated = Updated_member->value.GetBool();
                const Value::ConstMemberIterator SubmissionsRemaining_member = obj.FindMember("SubmissionsRemaining");
                if (SubmissionsRemaining_member != obj.MemberEnd() && !SubmissionsRemaining_member->value.IsNull()) SubmissionsRemaining = SubmissionsRemaining_member->value.GetInt();

                return true;
            }
        };

        struct RevokeAllBansForUserRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;

            RevokeAllBansForUserRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            RevokeAllBansForUserRequest(const RevokeAllBansForUserRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            RevokeAllBansForUserRequest(const rapidjson::Value& obj) : RevokeAllBansForUserRequest()
            {
                readFromValue(obj);
            }

            ~RevokeAllBansForUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct RevokeAllBansForUserResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            RevokeAllBansForUserResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            RevokeAllBansForUserResult(const RevokeAllBansForUserResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            RevokeAllBansForUserResult(const rapidjson::Value& obj) : RevokeAllBansForUserResult()
            {
                readFromValue(obj);
            }

            ~RevokeAllBansForUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct RevokeBansRequest : public PlayFabBaseModel
        {
            std::list<Aws::String> BanIds;

            RevokeBansRequest() :
                PlayFabBaseModel(),
                BanIds()
            {}

            RevokeBansRequest(const RevokeBansRequest& src) :
                PlayFabBaseModel(),
                BanIds(src.BanIds)
            {}

            RevokeBansRequest(const rapidjson::Value& obj) : RevokeBansRequest()
            {
                readFromValue(obj);
            }

            ~RevokeBansRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BanIds");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = BanIds.begin(); iter != BanIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanIds_member = obj.FindMember("BanIds");
    if (BanIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanIds.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct RevokeBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            RevokeBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            RevokeBansResult(const RevokeBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            RevokeBansResult(const rapidjson::Value& obj) : RevokeBansResult()
            {
                readFromValue(obj);
            }

            ~RevokeBansResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct RevokeInventoryItemRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String ItemInstanceId;

            RevokeInventoryItemRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ItemInstanceId()
            {}

            RevokeInventoryItemRequest(const RevokeInventoryItemRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId)
            {}

            RevokeInventoryItemRequest(const rapidjson::Value& obj) : RevokeInventoryItemRequest()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

                return true;
            }
        };

        struct RevokeInventoryResult : public PlayFabBaseModel
        {

            RevokeInventoryResult() :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const RevokeInventoryResult& src) :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const rapidjson::Value& obj) : RevokeInventoryResult()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SendPushNotificationRequest : public PlayFabBaseModel
        {
            Aws::String Recipient;
            Aws::String Message;
            Aws::String Subject;

            SendPushNotificationRequest() :
                PlayFabBaseModel(),
                Recipient(),
                Message(),
                Subject()
            {}

            SendPushNotificationRequest(const SendPushNotificationRequest& src) :
                PlayFabBaseModel(),
                Recipient(src.Recipient),
                Message(src.Message),
                Subject(src.Subject)
            {}

            SendPushNotificationRequest(const rapidjson::Value& obj) : SendPushNotificationRequest()
            {
                readFromValue(obj);
            }

            ~SendPushNotificationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Recipient"); writer.String(Recipient.c_str());
                writer.String("Message"); writer.String(Message.c_str());
                if (Subject.length() > 0) { writer.String("Subject"); writer.String(Subject.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Recipient_member = obj.FindMember("Recipient");
                if (Recipient_member != obj.MemberEnd() && !Recipient_member->value.IsNull()) Recipient = Recipient_member->value.GetString();
                const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
                if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
                const Value::ConstMemberIterator Subject_member = obj.FindMember("Subject");
                if (Subject_member != obj.MemberEnd() && !Subject_member->value.IsNull()) Subject = Subject_member->value.GetString();

                return true;
            }
        };

        struct SendPushNotificationResult : public PlayFabBaseModel
        {

            SendPushNotificationResult() :
                PlayFabBaseModel()
            {}

            SendPushNotificationResult(const SendPushNotificationResult& src) :
                PlayFabBaseModel()
            {}

            SendPushNotificationResult(const rapidjson::Value& obj) : SendPushNotificationResult()
            {
                readFromValue(obj);
            }

            ~SendPushNotificationResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetFriendTagsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String FriendPlayFabId;
            std::list<Aws::String> Tags;

            SetFriendTagsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                FriendPlayFabId(),
                Tags()
            {}

            SetFriendTagsRequest(const SetFriendTagsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                FriendPlayFabId(src.FriendPlayFabId),
                Tags(src.Tags)
            {}

            SetFriendTagsRequest(const rapidjson::Value& obj) : SetFriendTagsRequest()
            {
                readFromValue(obj);
            }

            ~SetFriendTagsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str());
                writer.String("Tags");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct SetGameServerInstanceDataRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;
            Aws::String GameServerData;

            SetGameServerInstanceDataRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                GameServerData()
            {}

            SetGameServerInstanceDataRequest(const SetGameServerInstanceDataRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                GameServerData(src.GameServerData)
            {}

            SetGameServerInstanceDataRequest(const rapidjson::Value& obj) : SetGameServerInstanceDataRequest()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.String("GameServerData"); writer.String(GameServerData.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator GameServerData_member = obj.FindMember("GameServerData");
                if (GameServerData_member != obj.MemberEnd() && !GameServerData_member->value.IsNull()) GameServerData = GameServerData_member->value.GetString();

                return true;
            }
        };

        struct SetGameServerInstanceDataResult : public PlayFabBaseModel
        {

            SetGameServerInstanceDataResult() :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceDataResult(const SetGameServerInstanceDataResult& src) :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceDataResult(const rapidjson::Value& obj) : SetGameServerInstanceDataResult()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetGameServerInstanceStateRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;
            GameInstanceState State;

            SetGameServerInstanceStateRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                State()
            {}

            SetGameServerInstanceStateRequest(const SetGameServerInstanceStateRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                State(src.State)
            {}

            SetGameServerInstanceStateRequest(const rapidjson::Value& obj) : SetGameServerInstanceStateRequest()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceStateRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.String("State"); writeGameInstanceStateEnumJSON(State, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator State_member = obj.FindMember("State");
                if (State_member != obj.MemberEnd() && !State_member->value.IsNull()) State = readGameInstanceStateFromValue(State_member->value);

                return true;
            }
        };

        struct SetGameServerInstanceStateResult : public PlayFabBaseModel
        {

            SetGameServerInstanceStateResult() :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceStateResult(const SetGameServerInstanceStateResult& src) :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceStateResult(const rapidjson::Value& obj) : SetGameServerInstanceStateResult()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceStateResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetGameServerInstanceTagsRequest : public PlayFabBaseModel
        {
            Aws::String LobbyId;
            std::map<Aws::String, Aws::String> Tags;

            SetGameServerInstanceTagsRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                Tags()
            {}

            SetGameServerInstanceTagsRequest(const SetGameServerInstanceTagsRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                Tags(src.Tags)
            {}

            SetGameServerInstanceTagsRequest(const rapidjson::Value& obj) : SetGameServerInstanceTagsRequest()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceTagsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId"); writer.String(LobbyId.c_str());
                writer.String("Tags");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Tags.begin(); iter != Tags.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Tags_member->value.MemberBegin(); iter != Tags_member->value.MemberEnd(); ++iter) {
            Tags[iter->name.GetString()] = iter->value.GetString();
        }
    }

                return true;
            }
        };

        struct SetGameServerInstanceTagsResult : public PlayFabBaseModel
        {

            SetGameServerInstanceTagsResult() :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceTagsResult(const SetGameServerInstanceTagsResult& src) :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceTagsResult(const rapidjson::Value& obj) : SetGameServerInstanceTagsResult()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceTagsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetPublisherDataRequest : public PlayFabBaseModel
        {
            Aws::String Key;
            Aws::String Value;

            SetPublisherDataRequest() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            SetPublisherDataRequest(const SetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            SetPublisherDataRequest(const rapidjson::Value& obj) : SetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~SetPublisherDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key"); writer.String(Key.c_str());
                if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

                return true;
            }
        };

        struct SetPublisherDataResult : public PlayFabBaseModel
        {

            SetPublisherDataResult() :
                PlayFabBaseModel()
            {}

            SetPublisherDataResult(const SetPublisherDataResult& src) :
                PlayFabBaseModel()
            {}

            SetPublisherDataResult(const rapidjson::Value& obj) : SetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~SetPublisherDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetTitleDataRequest : public PlayFabBaseModel
        {
            Aws::String Key;
            Aws::String Value;

            SetTitleDataRequest() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            SetTitleDataRequest(const SetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            SetTitleDataRequest(const rapidjson::Value& obj) : SetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~SetTitleDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key"); writer.String(Key.c_str());
                if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

                return true;
            }
        };

        struct SetTitleDataResult : public PlayFabBaseModel
        {

            SetTitleDataResult() :
                PlayFabBaseModel()
            {}

            SetTitleDataResult(const SetTitleDataResult& src) :
                PlayFabBaseModel()
            {}

            SetTitleDataResult(const rapidjson::Value& obj) : SetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~SetTitleDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct StatisticUpdate : public PlayFabBaseModel
        {
            Aws::String StatisticName;
            OptionalUint32 Version;
            Int32 Value;

            StatisticUpdate() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(),
                Value(0)
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version),
                Value(src.Value)
            {}

            StatisticUpdate(const rapidjson::Value& obj) : StatisticUpdate()
            {
                readFromValue(obj);
            }

            ~StatisticUpdate()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName"); writer.String(StatisticName.c_str());
                if (Version.notNull()) { writer.String("Version"); writer.Uint(Version); }
                writer.String("Value"); writer.Int(Value);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();

                return true;
            }
        };

        struct SubtractCharacterVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String VirtualCurrency;
            Int32 Amount;

            SubtractCharacterVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                VirtualCurrency(),
                Amount(0)
            {}

            SubtractCharacterVirtualCurrencyRequest(const SubtractCharacterVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            SubtractCharacterVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractCharacterVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~SubtractCharacterVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
                writer.String("Amount"); writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String VirtualCurrency;
            Int32 Amount;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                Amount(0)
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            SubtractUserVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~SubtractUserVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
                writer.String("Amount"); writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct UnlockContainerInstanceRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String ContainerItemInstanceId;
            Aws::String KeyItemInstanceId;
            Aws::String CatalogVersion;

            UnlockContainerInstanceRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ContainerItemInstanceId(),
                KeyItemInstanceId(),
                CatalogVersion()
            {}

            UnlockContainerInstanceRequest(const UnlockContainerInstanceRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ContainerItemInstanceId(src.ContainerItemInstanceId),
                KeyItemInstanceId(src.KeyItemInstanceId),
                CatalogVersion(src.CatalogVersion)
            {}

            UnlockContainerInstanceRequest(const rapidjson::Value& obj) : UnlockContainerInstanceRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerInstanceRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.String("ContainerItemInstanceId"); writer.String(ContainerItemInstanceId.c_str());
                if (KeyItemInstanceId.length() > 0) { writer.String("KeyItemInstanceId"); writer.String(KeyItemInstanceId.c_str()); }
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ContainerItemInstanceId_member = obj.FindMember("ContainerItemInstanceId");
                if (ContainerItemInstanceId_member != obj.MemberEnd() && !ContainerItemInstanceId_member->value.IsNull()) ContainerItemInstanceId = ContainerItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator KeyItemInstanceId_member = obj.FindMember("KeyItemInstanceId");
                if (KeyItemInstanceId_member != obj.MemberEnd() && !KeyItemInstanceId_member->value.IsNull()) KeyItemInstanceId = KeyItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct UnlockContainerItemRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String ContainerItemId;
            Aws::String CatalogVersion;

            UnlockContainerItemRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ContainerItemId(),
                CatalogVersion()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ContainerItemId(src.ContainerItemId),
                CatalogVersion(src.CatalogVersion)
            {}

            UnlockContainerItemRequest(const rapidjson::Value& obj) : UnlockContainerItemRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.String("ContainerItemId"); writer.String(ContainerItemId.c_str());
                if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ContainerItemId_member = obj.FindMember("ContainerItemId");
                if (ContainerItemId_member != obj.MemberEnd() && !ContainerItemId_member->value.IsNull()) ContainerItemId = ContainerItemId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct UnlockContainerItemResult : public PlayFabBaseModel
        {
            Aws::String UnlockedItemInstanceId;
            Aws::String UnlockedWithItemInstanceId;
            std::list<ItemInstance> GrantedItems;
            std::map<Aws::String, Uint32> VirtualCurrency;

            UnlockContainerItemResult() :
                PlayFabBaseModel(),
                UnlockedItemInstanceId(),
                UnlockedWithItemInstanceId(),
                GrantedItems(),
                VirtualCurrency()
            {}

            UnlockContainerItemResult(const UnlockContainerItemResult& src) :
                PlayFabBaseModel(),
                UnlockedItemInstanceId(src.UnlockedItemInstanceId),
                UnlockedWithItemInstanceId(src.UnlockedWithItemInstanceId),
                GrantedItems(src.GrantedItems),
                VirtualCurrency(src.VirtualCurrency)
            {}

            UnlockContainerItemResult(const rapidjson::Value& obj) : UnlockContainerItemResult()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UnlockedItemInstanceId.length() > 0) { writer.String("UnlockedItemInstanceId"); writer.String(UnlockedItemInstanceId.c_str()); }
                if (UnlockedWithItemInstanceId.length() > 0) { writer.String("UnlockedWithItemInstanceId"); writer.String(UnlockedWithItemInstanceId.c_str()); }
                if (!GrantedItems.empty()) {
    writer.String("GrantedItems");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = GrantedItems.begin(); iter != GrantedItems.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                if (!VirtualCurrency.empty()) {
    writer.String("VirtualCurrency");
    writer.StartObject();
    for (std::map<Aws::String, Uint32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UnlockedItemInstanceId_member = obj.FindMember("UnlockedItemInstanceId");
                if (UnlockedItemInstanceId_member != obj.MemberEnd() && !UnlockedItemInstanceId_member->value.IsNull()) UnlockedItemInstanceId = UnlockedItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator UnlockedWithItemInstanceId_member = obj.FindMember("UnlockedWithItemInstanceId");
                if (UnlockedWithItemInstanceId_member != obj.MemberEnd() && !UnlockedWithItemInstanceId_member->value.IsNull()) UnlockedWithItemInstanceId = UnlockedWithItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
    if (GrantedItems_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GrantedItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GrantedItems.push_back(ItemInstance(memberList[i]));
        }
    }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetUint();
        }
    }

                return true;
            }
        };

        struct UpdateAvatarUrlRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String ImageUrl;

            UpdateAvatarUrlRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                ImageUrl()
            {}

            UpdateAvatarUrlRequest(const UpdateAvatarUrlRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ImageUrl(src.ImageUrl)
            {}

            UpdateAvatarUrlRequest(const rapidjson::Value& obj) : UpdateAvatarUrlRequest()
            {
                readFromValue(obj);
            }

            ~UpdateAvatarUrlRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("ImageUrl"); writer.String(ImageUrl.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ImageUrl_member = obj.FindMember("ImageUrl");
                if (ImageUrl_member != obj.MemberEnd() && !ImageUrl_member->value.IsNull()) ImageUrl = ImageUrl_member->value.GetString();

                return true;
            }
        };

        struct UpdateBanRequest : public PlayFabBaseModel
        {
            Aws::String BanId;
            Aws::String Reason;
            OptionalTime Expires;
            Aws::String IPAddress;
            Aws::String MACAddress;
            OptionalBool Permanent;
            OptionalBool Active;

            UpdateBanRequest() :
                PlayFabBaseModel(),
                BanId(),
                Reason(),
                Expires(),
                IPAddress(),
                MACAddress(),
                Permanent(),
                Active()
            {}

            UpdateBanRequest(const UpdateBanRequest& src) :
                PlayFabBaseModel(),
                BanId(src.BanId),
                Reason(src.Reason),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Permanent(src.Permanent),
                Active(src.Active)
            {}

            UpdateBanRequest(const rapidjson::Value& obj) : UpdateBanRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBanRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BanId"); writer.String(BanId.c_str());
                if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
                if (Expires.notNull()) { writer.String("Expires"); writeDatetime(Expires, writer); }
                if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
                if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
                if (Permanent.notNull()) { writer.String("Permanent"); writer.Bool(Permanent); }
                if (Active.notNull()) { writer.String("Active"); writer.Bool(Active); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanId_member = obj.FindMember("BanId");
                if (BanId_member != obj.MemberEnd() && !BanId_member->value.IsNull()) BanId = BanId_member->value.GetString();
                const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
                if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
                if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
                const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
                if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
                const Value::ConstMemberIterator Permanent_member = obj.FindMember("Permanent");
                if (Permanent_member != obj.MemberEnd() && !Permanent_member->value.IsNull()) Permanent = Permanent_member->value.GetBool();
                const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
                if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();

                return true;
            }
        };

        struct UpdateBansRequest : public PlayFabBaseModel
        {
            std::list<UpdateBanRequest> Bans;

            UpdateBansRequest() :
                PlayFabBaseModel(),
                Bans()
            {}

            UpdateBansRequest(const UpdateBansRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans)
            {}

            UpdateBansRequest(const rapidjson::Value& obj) : UpdateBansRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBansRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Bans");
    writer.StartArray();
    for (std::list<UpdateBanRequest>::iterator iter = Bans.begin(); iter != Bans.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Bans_member = obj.FindMember("Bans");
    if (Bans_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Bans_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Bans.push_back(UpdateBanRequest(memberList[i]));
        }
    }

                return true;
            }
        };

        struct UpdateBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            UpdateBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            UpdateBansResult(const UpdateBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            UpdateBansResult(const rapidjson::Value& obj) : UpdateBansResult()
            {
                readFromValue(obj);
            }

            ~UpdateBansResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

                return true;
            }
        };

        struct UpdateCharacterDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            std::map<Aws::String, Aws::String> Data;
            std::list<Aws::String> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateCharacterDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateCharacterDataRequest(const rapidjson::Value& obj) : UpdateCharacterDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateCharacterDataResult : public PlayFabBaseModel
        {
            Uint32 DataVersion;

            UpdateCharacterDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateCharacterDataResult(const UpdateCharacterDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateCharacterDataResult(const rapidjson::Value& obj) : UpdateCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DataVersion"); writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct UpdateCharacterStatisticsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            std::map<Aws::String, Int32> CharacterStatistics;

            UpdateCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                CharacterStatistics()
            {}

            UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics)
            {}

            UpdateCharacterStatisticsRequest(const rapidjson::Value& obj) : UpdateCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                if (!CharacterStatistics.empty()) {
    writer.String("CharacterStatistics");
    writer.StartObject();
    for (std::map<Aws::String, Int32>::iterator iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
    if (CharacterStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
            CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }

                return true;
            }
        };

        struct UpdateCharacterStatisticsResult : public PlayFabBaseModel
        {

            UpdateCharacterStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdateCharacterStatisticsResult(const UpdateCharacterStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateCharacterStatisticsResult(const rapidjson::Value& obj) : UpdateCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdatePlayerStatisticsRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::list<StatisticUpdate> Statistics;
            OptionalBool ForceUpdate;

            UpdatePlayerStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Statistics(),
                ForceUpdate()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Statistics(src.Statistics),
                ForceUpdate(src.ForceUpdate)
            {}

            UpdatePlayerStatisticsRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("Statistics");
    writer.StartArray();
    for (std::list<StatisticUpdate>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
                if (ForceUpdate.notNull()) { writer.String("ForceUpdate"); writer.Bool(ForceUpdate); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statistics.push_back(StatisticUpdate(memberList[i]));
        }
    }
                const Value::ConstMemberIterator ForceUpdate_member = obj.FindMember("ForceUpdate");
                if (ForceUpdate_member != obj.MemberEnd() && !ForceUpdate_member->value.IsNull()) ForceUpdate = ForceUpdate_member->value.GetBool();

                return true;
            }
        };

        struct UpdatePlayerStatisticsResult : public PlayFabBaseModel
        {

            UpdatePlayerStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const UpdatePlayerStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const rapidjson::Value& obj) : UpdatePlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdateSharedGroupDataRequest : public PlayFabBaseModel
        {
            Aws::String SharedGroupId;
            std::map<Aws::String, Aws::String> Data;
            std::list<Aws::String> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateSharedGroupDataRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateSharedGroupDataRequest(const rapidjson::Value& obj) : UpdateSharedGroupDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateSharedGroupDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateSharedGroupDataResult : public PlayFabBaseModel
        {

            UpdateSharedGroupDataResult() :
                PlayFabBaseModel()
            {}

            UpdateSharedGroupDataResult(const UpdateSharedGroupDataResult& src) :
                PlayFabBaseModel()
            {}

            UpdateSharedGroupDataResult(const rapidjson::Value& obj) : UpdateSharedGroupDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateSharedGroupDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdateUserDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::map<Aws::String, Aws::String> Data;
            std::list<Aws::String> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateUserDataRequest(const rapidjson::Value& obj) : UpdateUserDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateUserDataResult : public PlayFabBaseModel
        {
            Uint32 DataVersion;

            UpdateUserDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateUserDataResult(const UpdateUserDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateUserDataResult(const rapidjson::Value& obj) : UpdateUserDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DataVersion"); writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct UpdateUserInternalDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            std::map<Aws::String, Aws::String> Data;
            std::list<Aws::String> KeysToRemove;

            UpdateUserInternalDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Data(),
                KeysToRemove()
            {}

            UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove)
            {}

            UpdateUserInternalDataRequest(const rapidjson::Value& obj) : UpdateUserInternalDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserInternalDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct UpdateUserInventoryItemDataRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String ItemInstanceId;
            std::map<Aws::String, Aws::String> Data;
            std::list<Aws::String> KeysToRemove;

            UpdateUserInventoryItemDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ItemInstanceId(),
                Data(),
                KeysToRemove()
            {}

            UpdateUserInventoryItemDataRequest(const UpdateUserInventoryItemDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove)
            {}

            UpdateUserInventoryItemDataRequest(const rapidjson::Value& obj) : UpdateUserInventoryItemDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserInventoryItemDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
                writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
                if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<Aws::String, Aws::String>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
                if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<Aws::String>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }

                return true;
            }
        };

        struct WriteEventResponse : public PlayFabBaseModel
        {
            Aws::String EventId;

            WriteEventResponse() :
                PlayFabBaseModel(),
                EventId()
            {}

            WriteEventResponse(const WriteEventResponse& src) :
                PlayFabBaseModel(),
                EventId(src.EventId)
            {}

            WriteEventResponse(const rapidjson::Value& obj) : WriteEventResponse()
            {
                readFromValue(obj);
            }

            ~WriteEventResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (EventId.length() > 0) { writer.String("EventId"); writer.String(EventId.c_str()); }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EventId_member = obj.FindMember("EventId");
                if (EventId_member != obj.MemberEnd() && !EventId_member->value.IsNull()) EventId = EventId_member->value.GetString();

                return true;
            }
        };

        struct WriteServerCharacterEventRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String CharacterId;
            Aws::String EventName;
            OptionalTime Timestamp;
            std::map<Aws::String, MultitypeVar> Body;

            WriteServerCharacterEventRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                EventName(),
                Timestamp(),
                Body()
            {}

            WriteServerCharacterEventRequest(const WriteServerCharacterEventRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                EventName(src.EventName),
                Timestamp(src.Timestamp),
                Body(src.Body)
            {}

            WriteServerCharacterEventRequest(const rapidjson::Value& obj) : WriteServerCharacterEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteServerCharacterEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("CharacterId"); writer.String(CharacterId.c_str());
                writer.String("EventName"); writer.String(EventName.c_str());
                if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
                if (!Body.empty()) {
    writer.String("Body");
    writer.StartObject();
    for (std::map<Aws::String, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }

                return true;
            }
        };

        struct WriteServerPlayerEventRequest : public PlayFabBaseModel
        {
            Aws::String PlayFabId;
            Aws::String EventName;
            OptionalTime Timestamp;
            std::map<Aws::String, MultitypeVar> Body;

            WriteServerPlayerEventRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                EventName(),
                Timestamp(),
                Body()
            {}

            WriteServerPlayerEventRequest(const WriteServerPlayerEventRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                EventName(src.EventName),
                Timestamp(src.Timestamp),
                Body(src.Body)
            {}

            WriteServerPlayerEventRequest(const rapidjson::Value& obj) : WriteServerPlayerEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteServerPlayerEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
                writer.String("EventName"); writer.String(EventName.c_str());
                if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
                if (!Body.empty()) {
    writer.String("Body");
    writer.StartObject();
    for (std::map<Aws::String, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }

                return true;
            }
        };

        struct WriteTitleEventRequest : public PlayFabBaseModel
        {
            Aws::String EventName;
            OptionalTime Timestamp;
            std::map<Aws::String, MultitypeVar> Body;

            WriteTitleEventRequest() :
                PlayFabBaseModel(),
                EventName(),
                Timestamp(),
                Body()
            {}

            WriteTitleEventRequest(const WriteTitleEventRequest& src) :
                PlayFabBaseModel(),
                EventName(src.EventName),
                Timestamp(src.Timestamp),
                Body(src.Body)
            {}

            WriteTitleEventRequest(const rapidjson::Value& obj) : WriteTitleEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteTitleEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("EventName"); writer.String(EventName.c_str());
                if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
                if (!Body.empty()) {
    writer.String("Body");
    writer.StartObject();
    for (std::map<Aws::String, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }

                return true;
            }
        };


    }
}
