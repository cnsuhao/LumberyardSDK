#pragma once

#include <PlayFabClientSdk/PlayFabBaseModel.h>
#include <aws/core/utils/json/JsonSerializer.h>

using namespace rapidjson;

namespace PlayFabClientSdk
{
    namespace EntityModels
    {
        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup,
            EntityTypesservice
        };

        inline void writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case EntityTypestitle: writer.String("title"); break;
            case EntityTypesmaster_player_account: writer.String("master_player_account"); break;
            case EntityTypestitle_player_account: writer.String("title_player_account"); break;
            case EntityTypescharacter: writer.String("character"); break;
            case EntityTypesgroup: writer.String("group"); break;
            case EntityTypesservice: writer.String("service"); break;

            }
        }

        inline EntityTypes readEntityTypesFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EntityTypes>(obj.GetInt());

            static std::map<const char *, EntityTypes, PlayFabClientSdk::StringCompare> _EntityTypesMap;
            if (_EntityTypesMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EntityTypesMap["title"] = EntityTypestitle;
                _EntityTypesMap["master_player_account"] = EntityTypesmaster_player_account;
                _EntityTypesMap["title_player_account"] = EntityTypestitle_player_account;
                _EntityTypesMap["character"] = EntityTypescharacter;
                _EntityTypesMap["group"] = EntityTypesgroup;
                _EntityTypesMap["service"] = EntityTypesservice;

            }

            auto output = _EntityTypesMap.find(obj.GetString());
            if (output != _EntityTypesMap.end())
                return output->second;

            return EntityTypestitle; // Basically critical fail
        }

        struct EntityKey : public PlayFabBaseModel
        {
            AZStd::string Id;
            Boxed<EntityTypes> Type;
            AZStd::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
            {}

            EntityKey(const rapidjson::Value& obj) : EntityKey()
            {
                readFromValue(obj);
            }

            ~EntityKey()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Id");
                writer.String(Id.c_str());
                if (Type.notNull()) {
                    writer.String("Type");
                    writeEntityTypesEnumJSON(Type, writer);
                }
                if (TypeString.length() > 0) {
                    writer.String("TypeString");
                    writer.String(TypeString.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator Type_member = obj.FindMember("Type");
                if (Type_member != obj.MemberEnd() && !Type_member->value.IsNull()) Type = readEntityTypesFromValue(Type_member->value);
                const Value::ConstMemberIterator TypeString_member = obj.FindMember("TypeString");
                if (TypeString_member != obj.MemberEnd() && !TypeString_member->value.IsNull()) TypeString = TypeString_member->value.GetString();

                return true;
            }
        };

        struct AbortFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<AZStd::string> FileNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalInt32 ProfileVersion;

            AbortFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            AbortFileUploadsRequest(const AbortFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            AbortFileUploadsRequest(const rapidjson::Value& obj) : AbortFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~AbortFileUploadsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("FileNames");
                writer.StartArray();
                for (auto iter = FileNames.begin(); iter != FileNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                if (ProfileVersion.notNull()) {
                    writer.String("ProfileVersion");
                    writer.Int(ProfileVersion);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
                if (FileNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FileNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FileNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct AbortFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;

            AbortFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                ProfileVersion(0)
            {}

            AbortFileUploadsResponse(const AbortFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                ProfileVersion(src.ProfileVersion)
            {}

            AbortFileUploadsResponse(const rapidjson::Value& obj) : AbortFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~AbortFileUploadsResponse()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct AcceptGroupApplicationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            AcceptGroupApplicationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            AcceptGroupApplicationRequest(const AcceptGroupApplicationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            AcceptGroupApplicationRequest(const rapidjson::Value& obj) : AcceptGroupApplicationRequest()
            {
                readFromValue(obj);
            }

            ~AcceptGroupApplicationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct AcceptGroupInvitationRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;
            EntityKey Group;

            AcceptGroupInvitationRequest() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Group()
            {}

            AcceptGroupInvitationRequest(const AcceptGroupInvitationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Group(src.Group)
            {}

            AcceptGroupInvitationRequest(const rapidjson::Value& obj) : AcceptGroupInvitationRequest()
            {
                readFromValue(obj);
            }

            ~AcceptGroupInvitationRequest()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct AddMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            AZStd::vector<EntityKey> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string RoleId;

            AddMembersRequest() :
                PlayFabBaseModel(),
                Group(),
                Members(),
                RoleId()
            {}

            AddMembersRequest(const AddMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                Members(src.Members),
                RoleId(src.RoleId)
            {}

            AddMembersRequest(const rapidjson::Value& obj) : AddMembersRequest()
            {
                readFromValue(obj);
            }

            ~AddMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.String("Members");
                writer.StartArray();
                for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityKey(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct ApplyToGroupRequest : public PlayFabBaseModel
        {
            OptionalBool AutoAcceptOutstandingInvite;
            EntityKey* Entity;
            EntityKey Group;

            ApplyToGroupRequest() :
                PlayFabBaseModel(),
                AutoAcceptOutstandingInvite(),
                Entity(nullptr),
                Group()
            {}

            ApplyToGroupRequest(const ApplyToGroupRequest& src) :
                PlayFabBaseModel(),
                AutoAcceptOutstandingInvite(src.AutoAcceptOutstandingInvite),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Group(src.Group)
            {}

            ApplyToGroupRequest(const rapidjson::Value& obj) : ApplyToGroupRequest()
            {
                readFromValue(obj);
            }

            ~ApplyToGroupRequest()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AutoAcceptOutstandingInvite.notNull()) {
                    writer.String("AutoAcceptOutstandingInvite");
                    writer.Bool(AutoAcceptOutstandingInvite);
                }
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AutoAcceptOutstandingInvite_member = obj.FindMember("AutoAcceptOutstandingInvite");
                if (AutoAcceptOutstandingInvite_member != obj.MemberEnd() && !AutoAcceptOutstandingInvite_member->value.IsNull()) AutoAcceptOutstandingInvite = AutoAcceptOutstandingInvite_member->value.GetBool();
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct EntityWithLineage : public PlayFabBaseModel
        {
            EntityKey* Key;
            std::map<AZStd::string, EntityKey> Lineage;

            EntityWithLineage() :
                PlayFabBaseModel(),
                Key(nullptr),
                Lineage()
            {}

            EntityWithLineage(const EntityWithLineage& src) :
                PlayFabBaseModel(),
                Key(src.Key ? new EntityKey(*src.Key) : nullptr),
                Lineage(src.Lineage)
            {}

            EntityWithLineage(const rapidjson::Value& obj) : EntityWithLineage()
            {
                readFromValue(obj);
            }

            ~EntityWithLineage()
            {
                if (Key != nullptr) delete Key;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Key != nullptr) {
                    writer.String("Key");
                    Key->writeJSON(writer);
                }
                if (!Lineage.empty()) {
                    writer.String("Lineage");
                    writer.StartObject();
                    for (auto iter = Lineage.begin(); iter != Lineage.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = new EntityKey(Key_member->value);
                const Value::ConstMemberIterator Lineage_member = obj.FindMember("Lineage");
                if (Lineage_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Lineage_member->value.MemberBegin(); iter != Lineage_member->value.MemberEnd(); ++iter) {
                        Lineage[iter->name.GetString()] = EntityKey(iter->value);
                    }
                }

                return true;
            }
        };

        struct ApplyToGroupResponse : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            time_t Expires;
            EntityKey* Group;

            ApplyToGroupResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Expires(0),
                Group(nullptr)
            {}

            ApplyToGroupResponse(const ApplyToGroupResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : nullptr),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr)
            {}

            ApplyToGroupResponse(const rapidjson::Value& obj) : ApplyToGroupResponse()
            {
                readFromValue(obj);
            }

            ~ApplyToGroupResponse()
            {
                if (Entity != nullptr) delete Entity;
                if (Group != nullptr) delete Group;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("Expires");
                writeDatetime(Expires, writer);
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);

                return true;
            }
        };

        struct BlockEntityRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            BlockEntityRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            BlockEntityRequest(const BlockEntityRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            BlockEntityRequest(const rapidjson::Value& obj) : BlockEntityRequest()
            {
                readFromValue(obj);
            }

            ~BlockEntityRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ChangeMemberRoleRequest : public PlayFabBaseModel
        {
            AZStd::string DestinationRoleId;
            EntityKey Group;
            AZStd::vector<EntityKey> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string OriginRoleId;

            ChangeMemberRoleRequest() :
                PlayFabBaseModel(),
                DestinationRoleId(),
                Group(),
                Members(),
                OriginRoleId()
            {}

            ChangeMemberRoleRequest(const ChangeMemberRoleRequest& src) :
                PlayFabBaseModel(),
                DestinationRoleId(src.DestinationRoleId),
                Group(src.Group),
                Members(src.Members),
                OriginRoleId(src.OriginRoleId)
            {}

            ChangeMemberRoleRequest(const rapidjson::Value& obj) : ChangeMemberRoleRequest()
            {
                readFromValue(obj);
            }

            ~ChangeMemberRoleRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DestinationRoleId.length() > 0) {
                    writer.String("DestinationRoleId");
                    writer.String(DestinationRoleId.c_str());
                }
                writer.String("Group");
                Group.writeJSON(writer);
                writer.String("Members");
                writer.StartArray();
                for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.String("OriginRoleId");
                writer.String(OriginRoleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DestinationRoleId_member = obj.FindMember("DestinationRoleId");
                if (DestinationRoleId_member != obj.MemberEnd() && !DestinationRoleId_member->value.IsNull()) DestinationRoleId = DestinationRoleId_member->value.GetString();
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityKey(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator OriginRoleId_member = obj.FindMember("OriginRoleId");
                if (OriginRoleId_member != obj.MemberEnd() && !OriginRoleId_member->value.IsNull()) OriginRoleId = OriginRoleId_member->value.GetString();

                return true;
            }
        };

        struct CreateGroupRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;
            AZStd::string GroupName;

            CreateGroupRequest() :
                PlayFabBaseModel(),
                Entity(nullptr),
                GroupName()
            {}

            CreateGroupRequest(const CreateGroupRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                GroupName(src.GroupName)
            {}

            CreateGroupRequest(const rapidjson::Value& obj) : CreateGroupRequest()
            {
                readFromValue(obj);
            }

            ~CreateGroupRequest()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("GroupName");
                writer.String(GroupName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();

                return true;
            }
        };

        struct CreateGroupResponse : public PlayFabBaseModel
        {
            AZStd::string AdminRoleId;
            time_t Created;
            EntityKey Group;
            AZStd::string GroupName;
            AZStd::string MemberRoleId;
            Int32 ProfileVersion;
            std::map<AZStd::string, AZStd::string> Roles;

            CreateGroupResponse() :
                PlayFabBaseModel(),
                AdminRoleId(),
                Created(0),
                Group(),
                GroupName(),
                MemberRoleId(),
                ProfileVersion(0),
                Roles()
            {}

            CreateGroupResponse(const CreateGroupResponse& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                Created(src.Created),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            CreateGroupResponse(const rapidjson::Value& obj) : CreateGroupResponse()
            {
                readFromValue(obj);
            }

            ~CreateGroupResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AdminRoleId.length() > 0) {
                    writer.String("AdminRoleId");
                    writer.String(AdminRoleId.c_str());
                }
                writer.String("Created");
                writeDatetime(Created, writer);
                writer.String("Group");
                Group.writeJSON(writer);
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                if (MemberRoleId.length() > 0) {
                    writer.String("MemberRoleId");
                    writer.String(MemberRoleId.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!Roles.empty()) {
                    writer.String("Roles");
                    writer.StartObject();
                    for (auto iter = Roles.begin(); iter != Roles.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
                if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
                const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
                if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
                if (Roles_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Roles_member->value.MemberBegin(); iter != Roles_member->value.MemberEnd(); ++iter) {
                        Roles[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct CreateGroupRoleRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            AZStd::string RoleId;
            AZStd::string RoleName;

            CreateGroupRoleRequest() :
                PlayFabBaseModel(),
                Group(),
                RoleId(),
                RoleName()
            {}

            CreateGroupRoleRequest(const CreateGroupRoleRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            CreateGroupRoleRequest(const rapidjson::Value& obj) : CreateGroupRoleRequest()
            {
                readFromValue(obj);
            }

            ~CreateGroupRoleRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.String("RoleId");
                writer.String(RoleId.c_str());
                writer.String("RoleName");
                writer.String(RoleName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct CreateGroupRoleResponse : public PlayFabBaseModel
        {
            Int32 ProfileVersion;
            AZStd::string RoleId;
            AZStd::string RoleName;

            CreateGroupRoleResponse() :
                PlayFabBaseModel(),
                ProfileVersion(0),
                RoleId(),
                RoleName()
            {}

            CreateGroupRoleResponse(const CreateGroupRoleResponse& src) :
                PlayFabBaseModel(),
                ProfileVersion(src.ProfileVersion),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            CreateGroupRoleResponse(const rapidjson::Value& obj) : CreateGroupRoleResponse()
            {
                readFromValue(obj);
            }

            ~CreateGroupRoleResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                if (RoleName.length() > 0) {
                    writer.String("RoleName");
                    writer.String(RoleName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct DeleteFilesRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<AZStd::string> FileNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalInt32 ProfileVersion;

            DeleteFilesRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            DeleteFilesRequest(const DeleteFilesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            DeleteFilesRequest(const rapidjson::Value& obj) : DeleteFilesRequest()
            {
                readFromValue(obj);
            }

            ~DeleteFilesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("FileNames");
                writer.StartArray();
                for (auto iter = FileNames.begin(); iter != FileNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                if (ProfileVersion.notNull()) {
                    writer.String("ProfileVersion");
                    writer.Int(ProfileVersion);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
                if (FileNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FileNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FileNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct DeleteFilesResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;

            DeleteFilesResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                ProfileVersion(0)
            {}

            DeleteFilesResponse(const DeleteFilesResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                ProfileVersion(src.ProfileVersion)
            {}

            DeleteFilesResponse(const rapidjson::Value& obj) : DeleteFilesResponse()
            {
                readFromValue(obj);
            }

            ~DeleteFilesResponse()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct DeleteGroupRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            DeleteGroupRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            DeleteGroupRequest(const DeleteGroupRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            DeleteGroupRequest(const rapidjson::Value& obj) : DeleteGroupRequest()
            {
                readFromValue(obj);
            }

            ~DeleteGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct DeleteRoleRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            AZStd::string RoleId;

            DeleteRoleRequest() :
                PlayFabBaseModel(),
                Group(),
                RoleId()
            {}

            DeleteRoleRequest(const DeleteRoleRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            DeleteRoleRequest(const rapidjson::Value& obj) : DeleteRoleRequest()
            {
                readFromValue(obj);
            }

            ~DeleteRoleRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        inline void writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case EffectTypeAllow: writer.String("Allow"); break;
            case EffectTypeDeny: writer.String("Deny"); break;

            }
        }

        inline EffectType readEffectTypeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EffectType>(obj.GetInt());

            static std::map<const char *, EffectType, PlayFabClientSdk::StringCompare> _EffectTypeMap;
            if (_EffectTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EffectTypeMap["Allow"] = EffectTypeAllow;
                _EffectTypeMap["Deny"] = EffectTypeDeny;

            }

            auto output = _EffectTypeMap.find(obj.GetString());
            if (output != _EffectTypeMap.end())
                return output->second;

            return EffectTypeAllow; // Basically critical fail
        }

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

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct EntityDataObject : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            AZStd::string EscapedDataObject;
            AZStd::string ObjectName;

            EntityDataObject() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            EntityDataObject(const EntityDataObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            EntityDataObject(const rapidjson::Value& obj) : EntityDataObject()
            {
                readFromValue(obj);
            }

            ~EntityDataObject()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataObject.notNull()) {
                    writer.String("DataObject");
                    DataObject.writeJSON(writer);
                }
                if (EscapedDataObject.length() > 0) {
                    writer.String("EscapedDataObject");
                    writer.String(EscapedDataObject.c_str());
                }
                if (ObjectName.length() > 0) {
                    writer.String("ObjectName");
                    writer.String(ObjectName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataObject_member = obj.FindMember("DataObject");
                if (DataObject_member != obj.MemberEnd() && !DataObject_member->value.IsNull()) DataObject = MultitypeVar(DataObject_member->value);
                const Value::ConstMemberIterator EscapedDataObject_member = obj.FindMember("EscapedDataObject");
                if (EscapedDataObject_member != obj.MemberEnd() && !EscapedDataObject_member->value.IsNull()) EscapedDataObject = EscapedDataObject_member->value.GetString();
                const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
                if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();

                return true;
            }
        };

        struct EntityMemberRole : public PlayFabBaseModel
        {
            AZStd::vector<EntityWithLineage> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string RoleId;
            AZStd::string RoleName;

            EntityMemberRole() :
                PlayFabBaseModel(),
                Members(),
                RoleId(),
                RoleName()
            {}

            EntityMemberRole(const EntityMemberRole& src) :
                PlayFabBaseModel(),
                Members(src.Members),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            EntityMemberRole(const rapidjson::Value& obj) : EntityMemberRole()
            {
                readFromValue(obj);
            }

            ~EntityMemberRole()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Members.empty()) {
                    writer.String("Members");
                    writer.StartArray();
                    for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                if (RoleName.length() > 0) {
                    writer.String("RoleName");
                    writer.String(RoleName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityWithLineage(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct EntityPermissionStatement : public PlayFabBaseModel
        {
            AZStd::string Action;
            AZStd::string Comment;
            MultitypeVar Condition;
            EffectType Effect;
            MultitypeVar Principal;
            AZStd::string Resource;

            EntityPermissionStatement() :
                PlayFabBaseModel(),
                Action(),
                Comment(),
                Condition(),
                Effect(),
                Principal(),
                Resource()
            {}

            EntityPermissionStatement(const EntityPermissionStatement& src) :
                PlayFabBaseModel(),
                Action(src.Action),
                Comment(src.Comment),
                Condition(src.Condition),
                Effect(src.Effect),
                Principal(src.Principal),
                Resource(src.Resource)
            {}

            EntityPermissionStatement(const rapidjson::Value& obj) : EntityPermissionStatement()
            {
                readFromValue(obj);
            }

            ~EntityPermissionStatement()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Action");
                writer.String(Action.c_str());
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                if (Condition.notNull()) {
                    writer.String("Condition");
                    Condition.writeJSON(writer);
                }
                writer.String("Effect");
                writeEffectTypeEnumJSON(Effect, writer);
                writer.String("Principal");
                Principal.writeJSON(writer);
                writer.String("Resource");
                writer.String(Resource.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Action_member = obj.FindMember("Action");
                if (Action_member != obj.MemberEnd() && !Action_member->value.IsNull()) Action = Action_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator Condition_member = obj.FindMember("Condition");
                if (Condition_member != obj.MemberEnd() && !Condition_member->value.IsNull()) Condition = MultitypeVar(Condition_member->value);
                const Value::ConstMemberIterator Effect_member = obj.FindMember("Effect");
                if (Effect_member != obj.MemberEnd() && !Effect_member->value.IsNull()) Effect = readEffectTypeFromValue(Effect_member->value);
                const Value::ConstMemberIterator Principal_member = obj.FindMember("Principal");
                if (Principal_member != obj.MemberEnd() && !Principal_member->value.IsNull()) Principal = MultitypeVar(Principal_member->value);
                const Value::ConstMemberIterator Resource_member = obj.FindMember("Resource");
                if (Resource_member != obj.MemberEnd() && !Resource_member->value.IsNull()) Resource = Resource_member->value.GetString();

                return true;
            }
        };

        struct EntityProfileFileMetadata : public PlayFabBaseModel
        {
            AZStd::string Checksum;
            AZStd::string FileName;
            time_t LastModified;
            Int32 Size;

            EntityProfileFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                FileName(),
                LastModified(0),
                Size(0)
            {}

            EntityProfileFileMetadata(const EntityProfileFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            EntityProfileFileMetadata(const rapidjson::Value& obj) : EntityProfileFileMetadata()
            {
                readFromValue(obj);
            }

            ~EntityProfileFileMetadata()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Checksum.length() > 0) {
                    writer.String("Checksum");
                    writer.String(Checksum.c_str());
                }
                if (FileName.length() > 0) {
                    writer.String("FileName");
                    writer.String(FileName.c_str());
                }
                writer.String("LastModified");
                writeDatetime(LastModified, writer);
                writer.String("Size");
                writer.Int(Size);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Checksum_member = obj.FindMember("Checksum");
                if (Checksum_member != obj.MemberEnd() && !Checksum_member->value.IsNull()) Checksum = Checksum_member->value.GetString();
                const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
                if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
                const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
                if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);
                const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
                if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetInt();

                return true;
            }
        };

        struct EntityProfileBody : public PlayFabBaseModel
        {
            EntityKey* Entity;
            AZStd::string EntityChain;
            std::map<AZStd::string, EntityProfileFileMetadata> Files;
            std::map<AZStd::string, EntityDataObject> Objects;
            AZStd::vector<EntityPermissionStatement> Permissions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Int32 VersionNumber;

            EntityProfileBody() :
                PlayFabBaseModel(),
                Entity(nullptr),
                EntityChain(),
                Files(),
                Objects(),
                Permissions(),
                VersionNumber(0)
            {}

            EntityProfileBody(const EntityProfileBody& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                EntityChain(src.EntityChain),
                Files(src.Files),
                Objects(src.Objects),
                Permissions(src.Permissions),
                VersionNumber(src.VersionNumber)
            {}

            EntityProfileBody(const rapidjson::Value& obj) : EntityProfileBody()
            {
                readFromValue(obj);
            }

            ~EntityProfileBody()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                if (EntityChain.length() > 0) {
                    writer.String("EntityChain");
                    writer.String(EntityChain.c_str());
                }
                if (!Files.empty()) {
                    writer.String("Files");
                    writer.StartObject();
                    for (auto iter = Files.begin(); iter != Files.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                if (!Objects.empty()) {
                    writer.String("Objects");
                    writer.StartObject();
                    for (auto iter = Objects.begin(); iter != Objects.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                if (!Permissions.empty()) {
                    writer.String("Permissions");
                    writer.StartArray();
                    for (auto iter = Permissions.begin(); iter != Permissions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.String("VersionNumber");
                writer.Int(VersionNumber);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator EntityChain_member = obj.FindMember("EntityChain");
                if (EntityChain_member != obj.MemberEnd() && !EntityChain_member->value.IsNull()) EntityChain = EntityChain_member->value.GetString();
                const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
                if (Files_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Files_member->value.MemberBegin(); iter != Files_member->value.MemberEnd(); ++iter) {
                        Files[iter->name.GetString()] = EntityProfileFileMetadata(iter->value);
                    }
                }
                const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
                if (Objects_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Objects_member->value.MemberBegin(); iter != Objects_member->value.MemberEnd(); ++iter) {
                        Objects[iter->name.GetString()] = EntityDataObject(iter->value);
                    }
                }
                const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
                if (Permissions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Permissions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Permissions.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VersionNumber_member = obj.FindMember("VersionNumber");
                if (VersionNumber_member != obj.MemberEnd() && !VersionNumber_member->value.IsNull()) VersionNumber = VersionNumber_member->value.GetInt();

                return true;
            }
        };

        struct FinalizeFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<AZStd::string> FileNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            FinalizeFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames()
            {}

            FinalizeFileUploadsRequest(const FinalizeFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames)
            {}

            FinalizeFileUploadsRequest(const rapidjson::Value& obj) : FinalizeFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~FinalizeFileUploadsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("FileNames");
                writer.StartArray();
                for (auto iter = FileNames.begin(); iter != FileNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
                if (FileNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FileNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FileNames.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetFileMetadata : public PlayFabBaseModel
        {
            AZStd::string Checksum;
            AZStd::string DownloadUrl;
            AZStd::string FileName;
            time_t LastModified;
            Int32 Size;

            GetFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                DownloadUrl(),
                FileName(),
                LastModified(0),
                Size(0)
            {}

            GetFileMetadata(const GetFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                DownloadUrl(src.DownloadUrl),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            GetFileMetadata(const rapidjson::Value& obj) : GetFileMetadata()
            {
                readFromValue(obj);
            }

            ~GetFileMetadata()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Checksum.length() > 0) {
                    writer.String("Checksum");
                    writer.String(Checksum.c_str());
                }
                if (DownloadUrl.length() > 0) {
                    writer.String("DownloadUrl");
                    writer.String(DownloadUrl.c_str());
                }
                if (FileName.length() > 0) {
                    writer.String("FileName");
                    writer.String(FileName.c_str());
                }
                writer.String("LastModified");
                writeDatetime(LastModified, writer);
                writer.String("Size");
                writer.Int(Size);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Checksum_member = obj.FindMember("Checksum");
                if (Checksum_member != obj.MemberEnd() && !Checksum_member->value.IsNull()) Checksum = Checksum_member->value.GetString();
                const Value::ConstMemberIterator DownloadUrl_member = obj.FindMember("DownloadUrl");
                if (DownloadUrl_member != obj.MemberEnd() && !DownloadUrl_member->value.IsNull()) DownloadUrl = DownloadUrl_member->value.GetString();
                const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
                if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
                const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
                if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);
                const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
                if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetInt();

                return true;
            }
        };

        struct FinalizeFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<AZStd::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            FinalizeFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Metadata(),
                ProfileVersion(0)
            {}

            FinalizeFileUploadsResponse(const FinalizeFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            FinalizeFileUploadsResponse(const rapidjson::Value& obj) : FinalizeFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~FinalizeFileUploadsResponse()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                if (!Metadata.empty()) {
                    writer.String("Metadata");
                    writer.StartObject();
                    for (auto iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
                if (Metadata_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
                        Metadata[iter->name.GetString()] = GetFileMetadata(iter->value);
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct GetEntityProfileRequest : public PlayFabBaseModel
        {
            OptionalBool DataAsObject;
            EntityKey Entity;

            GetEntityProfileRequest() :
                PlayFabBaseModel(),
                DataAsObject(),
                Entity()
            {}

            GetEntityProfileRequest(const GetEntityProfileRequest& src) :
                PlayFabBaseModel(),
                DataAsObject(src.DataAsObject),
                Entity(src.Entity)
            {}

            GetEntityProfileRequest(const rapidjson::Value& obj) : GetEntityProfileRequest()
            {
                readFromValue(obj);
            }

            ~GetEntityProfileRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataAsObject.notNull()) {
                    writer.String("DataAsObject");
                    writer.Bool(DataAsObject);
                }
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataAsObject_member = obj.FindMember("DataAsObject");
                if (DataAsObject_member != obj.MemberEnd() && !DataAsObject_member->value.IsNull()) DataAsObject = DataAsObject_member->value.GetBool();
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);

                return true;
            }
        };

        struct GetEntityProfileResponse : public PlayFabBaseModel
        {
            EntityProfileBody* Profile;

            GetEntityProfileResponse() :
                PlayFabBaseModel(),
                Profile(nullptr)
            {}

            GetEntityProfileResponse(const GetEntityProfileResponse& src) :
                PlayFabBaseModel(),
                Profile(src.Profile ? new EntityProfileBody(*src.Profile) : nullptr)
            {}

            GetEntityProfileResponse(const rapidjson::Value& obj) : GetEntityProfileResponse()
            {
                readFromValue(obj);
            }

            ~GetEntityProfileResponse()
            {
                if (Profile != nullptr) delete Profile;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Profile != nullptr) {
                    writer.String("Profile");
                    Profile->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
                if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new EntityProfileBody(Profile_member->value);

                return true;
            }
        };

        struct GetEntityProfilesRequest : public PlayFabBaseModel
        {
            OptionalBool DataAsObject;
            AZStd::vector<EntityKey> Entities; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetEntityProfilesRequest() :
                PlayFabBaseModel(),
                DataAsObject(),
                Entities()
            {}

            GetEntityProfilesRequest(const GetEntityProfilesRequest& src) :
                PlayFabBaseModel(),
                DataAsObject(src.DataAsObject),
                Entities(src.Entities)
            {}

            GetEntityProfilesRequest(const rapidjson::Value& obj) : GetEntityProfilesRequest()
            {
                readFromValue(obj);
            }

            ~GetEntityProfilesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataAsObject.notNull()) {
                    writer.String("DataAsObject");
                    writer.Bool(DataAsObject);
                }
                writer.String("Entities");
                writer.StartArray();
                for (auto iter = Entities.begin(); iter != Entities.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataAsObject_member = obj.FindMember("DataAsObject");
                if (DataAsObject_member != obj.MemberEnd() && !DataAsObject_member->value.IsNull()) DataAsObject = DataAsObject_member->value.GetBool();
                const Value::ConstMemberIterator Entities_member = obj.FindMember("Entities");
                if (Entities_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Entities_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Entities.push_back(EntityKey(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetEntityProfilesResponse : public PlayFabBaseModel
        {
            AZStd::vector<EntityProfileBody> Profiles; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetEntityProfilesResponse() :
                PlayFabBaseModel(),
                Profiles()
            {}

            GetEntityProfilesResponse(const GetEntityProfilesResponse& src) :
                PlayFabBaseModel(),
                Profiles(src.Profiles)
            {}

            GetEntityProfilesResponse(const rapidjson::Value& obj) : GetEntityProfilesResponse()
            {
                readFromValue(obj);
            }

            ~GetEntityProfilesResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Profiles.empty()) {
                    writer.String("Profiles");
                    writer.StartArray();
                    for (auto iter = Profiles.begin(); iter != Profiles.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Profiles_member = obj.FindMember("Profiles");
                if (Profiles_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Profiles_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Profiles.push_back(EntityProfileBody(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetEntityTokenRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            GetEntityTokenRequest() :
                PlayFabBaseModel(),
                Entity(nullptr)
            {}

            GetEntityTokenRequest(const GetEntityTokenRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr)
            {}

            GetEntityTokenRequest(const rapidjson::Value& obj) : GetEntityTokenRequest()
            {
                readFromValue(obj);
            }

            ~GetEntityTokenRequest()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

                return true;
            }
        };

        struct GetEntityTokenResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            AZStd::string EntityToken;
            OptionalTime TokenExpiration;

            GetEntityTokenResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                EntityToken(),
                TokenExpiration()
            {}

            GetEntityTokenResponse(const GetEntityTokenResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            GetEntityTokenResponse(const rapidjson::Value& obj) : GetEntityTokenResponse()
            {
                readFromValue(obj);
            }

            ~GetEntityTokenResponse()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                if (EntityToken.length() > 0) {
                    writer.String("EntityToken");
                    writer.String(EntityToken.c_str());
                }
                if (TokenExpiration.notNull()) {
                    writer.String("TokenExpiration");
                    writeDatetime(TokenExpiration, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator EntityToken_member = obj.FindMember("EntityToken");
                if (EntityToken_member != obj.MemberEnd() && !EntityToken_member->value.IsNull()) EntityToken = EntityToken_member->value.GetString();
                const Value::ConstMemberIterator TokenExpiration_member = obj.FindMember("TokenExpiration");
                if (TokenExpiration_member != obj.MemberEnd() && !TokenExpiration_member->value.IsNull()) TokenExpiration = readDatetime(TokenExpiration_member->value);

                return true;
            }
        };

        struct GetFilesRequest : public PlayFabBaseModel
        {
            EntityKey Entity;

            GetFilesRequest() :
                PlayFabBaseModel(),
                Entity()
            {}

            GetFilesRequest(const GetFilesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity)
            {}

            GetFilesRequest(const rapidjson::Value& obj) : GetFilesRequest()
            {
                readFromValue(obj);
            }

            ~GetFilesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);

                return true;
            }
        };

        struct GetFilesResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<AZStd::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            GetFilesResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Metadata(),
                ProfileVersion(0)
            {}

            GetFilesResponse(const GetFilesResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            GetFilesResponse(const rapidjson::Value& obj) : GetFilesResponse()
            {
                readFromValue(obj);
            }

            ~GetFilesResponse()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                if (!Metadata.empty()) {
                    writer.String("Metadata");
                    writer.StartObject();
                    for (auto iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
                if (Metadata_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
                        Metadata[iter->name.GetString()] = GetFileMetadata(iter->value);
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct GetGlobalPolicyRequest : public PlayFabBaseModel
        {

            GetGlobalPolicyRequest() :
                PlayFabBaseModel()
            {}

            GetGlobalPolicyRequest(const GetGlobalPolicyRequest& src) :
                PlayFabBaseModel()
            {}

            GetGlobalPolicyRequest(const rapidjson::Value& obj) : GetGlobalPolicyRequest()
            {
                readFromValue(obj);
            }

            ~GetGlobalPolicyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetGlobalPolicyResponse : public PlayFabBaseModel
        {
            AZStd::vector<EntityPermissionStatement> Permissions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetGlobalPolicyResponse() :
                PlayFabBaseModel(),
                Permissions()
            {}

            GetGlobalPolicyResponse(const GetGlobalPolicyResponse& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            GetGlobalPolicyResponse(const rapidjson::Value& obj) : GetGlobalPolicyResponse()
            {
                readFromValue(obj);
            }

            ~GetGlobalPolicyResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Permissions.empty()) {
                    writer.String("Permissions");
                    writer.StartArray();
                    for (auto iter = Permissions.begin(); iter != Permissions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
                if (Permissions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Permissions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Permissions.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetGroupRequest : public PlayFabBaseModel
        {
            EntityKey* Group;
            AZStd::string GroupName;

            GetGroupRequest() :
                PlayFabBaseModel(),
                Group(nullptr),
                GroupName()
            {}

            GetGroupRequest(const GetGroupRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr),
                GroupName(src.GroupName)
            {}

            GetGroupRequest(const rapidjson::Value& obj) : GetGroupRequest()
            {
                readFromValue(obj);
            }

            ~GetGroupRequest()
            {
                if (Group != nullptr) delete Group;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();

                return true;
            }
        };

        struct GetGroupResponse : public PlayFabBaseModel
        {
            AZStd::string AdminRoleId;
            time_t Created;
            EntityKey Group;
            AZStd::string GroupName;
            AZStd::string MemberRoleId;
            Int32 ProfileVersion;
            std::map<AZStd::string, AZStd::string> Roles;

            GetGroupResponse() :
                PlayFabBaseModel(),
                AdminRoleId(),
                Created(0),
                Group(),
                GroupName(),
                MemberRoleId(),
                ProfileVersion(0),
                Roles()
            {}

            GetGroupResponse(const GetGroupResponse& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                Created(src.Created),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            GetGroupResponse(const rapidjson::Value& obj) : GetGroupResponse()
            {
                readFromValue(obj);
            }

            ~GetGroupResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AdminRoleId.length() > 0) {
                    writer.String("AdminRoleId");
                    writer.String(AdminRoleId.c_str());
                }
                writer.String("Created");
                writeDatetime(Created, writer);
                writer.String("Group");
                Group.writeJSON(writer);
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                if (MemberRoleId.length() > 0) {
                    writer.String("MemberRoleId");
                    writer.String(MemberRoleId.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!Roles.empty()) {
                    writer.String("Roles");
                    writer.StartObject();
                    for (auto iter = Roles.begin(); iter != Roles.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
                if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
                const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
                if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
                if (Roles_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Roles_member->value.MemberBegin(); iter != Roles_member->value.MemberEnd(); ++iter) {
                        Roles[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct GetObjectsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            OptionalBool EscapeObject;

            GetObjectsRequest() :
                PlayFabBaseModel(),
                Entity(),
                EscapeObject()
            {}

            GetObjectsRequest(const GetObjectsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                EscapeObject(src.EscapeObject)
            {}

            GetObjectsRequest(const rapidjson::Value& obj) : GetObjectsRequest()
            {
                readFromValue(obj);
            }

            ~GetObjectsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                if (EscapeObject.notNull()) {
                    writer.String("EscapeObject");
                    writer.Bool(EscapeObject);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator EscapeObject_member = obj.FindMember("EscapeObject");
                if (EscapeObject_member != obj.MemberEnd() && !EscapeObject_member->value.IsNull()) EscapeObject = EscapeObject_member->value.GetBool();

                return true;
            }
        };

        struct ObjectResult : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            AZStd::string EscapedDataObject;
            AZStd::string ObjectName;

            ObjectResult() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            ObjectResult(const ObjectResult& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ObjectResult(const rapidjson::Value& obj) : ObjectResult()
            {
                readFromValue(obj);
            }

            ~ObjectResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataObject.notNull()) {
                    writer.String("DataObject");
                    DataObject.writeJSON(writer);
                }
                if (EscapedDataObject.length() > 0) {
                    writer.String("EscapedDataObject");
                    writer.String(EscapedDataObject.c_str());
                }
                if (ObjectName.length() > 0) {
                    writer.String("ObjectName");
                    writer.String(ObjectName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataObject_member = obj.FindMember("DataObject");
                if (DataObject_member != obj.MemberEnd() && !DataObject_member->value.IsNull()) DataObject = MultitypeVar(DataObject_member->value);
                const Value::ConstMemberIterator EscapedDataObject_member = obj.FindMember("EscapedDataObject");
                if (EscapedDataObject_member != obj.MemberEnd() && !EscapedDataObject_member->value.IsNull()) EscapedDataObject = EscapedDataObject_member->value.GetString();
                const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
                if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();

                return true;
            }
        };

        struct GetObjectsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<AZStd::string, ObjectResult> Objects;
            Int32 ProfileVersion;

            GetObjectsResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Objects(),
                ProfileVersion(0)
            {}

            GetObjectsResponse(const GetObjectsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                Objects(src.Objects),
                ProfileVersion(src.ProfileVersion)
            {}

            GetObjectsResponse(const rapidjson::Value& obj) : GetObjectsResponse()
            {
                readFromValue(obj);
            }

            ~GetObjectsResponse()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                if (!Objects.empty()) {
                    writer.String("Objects");
                    writer.StartObject();
                    for (auto iter = Objects.begin(); iter != Objects.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
                if (Objects_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Objects_member->value.MemberBegin(); iter != Objects_member->value.MemberEnd(); ++iter) {
                        Objects[iter->name.GetString()] = ObjectResult(iter->value);
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct GroupApplication : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            time_t Expires;
            EntityKey* Group;

            GroupApplication() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Expires(0),
                Group(nullptr)
            {}

            GroupApplication(const GroupApplication& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : nullptr),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr)
            {}

            GroupApplication(const rapidjson::Value& obj) : GroupApplication()
            {
                readFromValue(obj);
            }

            ~GroupApplication()
            {
                if (Entity != nullptr) delete Entity;
                if (Group != nullptr) delete Group;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("Expires");
                writeDatetime(Expires, writer);
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);

                return true;
            }
        };

        struct GroupBlock : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            EntityKey Group;

            GroupBlock() :
                PlayFabBaseModel(),
                Entity(nullptr),
                Group()
            {}

            GroupBlock(const GroupBlock& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : nullptr),
                Group(src.Group)
            {}

            GroupBlock(const rapidjson::Value& obj) : GroupBlock()
            {
                readFromValue(obj);
            }

            ~GroupBlock()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct GroupInvitation : public PlayFabBaseModel
        {
            time_t Expires;
            EntityKey* Group;
            EntityWithLineage* InvitedByEntity;
            EntityWithLineage* InvitedEntity;
            AZStd::string RoleId;

            GroupInvitation() :
                PlayFabBaseModel(),
                Expires(0),
                Group(nullptr),
                InvitedByEntity(nullptr),
                InvitedEntity(nullptr),
                RoleId()
            {}

            GroupInvitation(const GroupInvitation& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr),
                InvitedByEntity(src.InvitedByEntity ? new EntityWithLineage(*src.InvitedByEntity) : nullptr),
                InvitedEntity(src.InvitedEntity ? new EntityWithLineage(*src.InvitedEntity) : nullptr),
                RoleId(src.RoleId)
            {}

            GroupInvitation(const rapidjson::Value& obj) : GroupInvitation()
            {
                readFromValue(obj);
            }

            ~GroupInvitation()
            {
                if (Group != nullptr) delete Group;
                if (InvitedByEntity != nullptr) delete InvitedByEntity;
                if (InvitedEntity != nullptr) delete InvitedEntity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Expires");
                writeDatetime(Expires, writer);
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                if (InvitedByEntity != nullptr) {
                    writer.String("InvitedByEntity");
                    InvitedByEntity->writeJSON(writer);
                }
                if (InvitedEntity != nullptr) {
                    writer.String("InvitedEntity");
                    InvitedEntity->writeJSON(writer);
                }
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
                const Value::ConstMemberIterator InvitedByEntity_member = obj.FindMember("InvitedByEntity");
                if (InvitedByEntity_member != obj.MemberEnd() && !InvitedByEntity_member->value.IsNull()) InvitedByEntity = new EntityWithLineage(InvitedByEntity_member->value);
                const Value::ConstMemberIterator InvitedEntity_member = obj.FindMember("InvitedEntity");
                if (InvitedEntity_member != obj.MemberEnd() && !InvitedEntity_member->value.IsNull()) InvitedEntity = new EntityWithLineage(InvitedEntity_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct GroupRole : public PlayFabBaseModel
        {
            AZStd::string RoleId;
            AZStd::string RoleName;

            GroupRole() :
                PlayFabBaseModel(),
                RoleId(),
                RoleName()
            {}

            GroupRole(const GroupRole& src) :
                PlayFabBaseModel(),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            GroupRole(const rapidjson::Value& obj) : GroupRole()
            {
                readFromValue(obj);
            }

            ~GroupRole()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                if (RoleName.length() > 0) {
                    writer.String("RoleName");
                    writer.String(RoleName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct GroupWithRoles : public PlayFabBaseModel
        {
            EntityKey* Group;
            AZStd::string GroupName;
            Int32 ProfileVersion;
            AZStd::vector<GroupRole> Roles; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GroupWithRoles() :
                PlayFabBaseModel(),
                Group(nullptr),
                GroupName(),
                ProfileVersion(0),
                Roles()
            {}

            GroupWithRoles(const GroupWithRoles& src) :
                PlayFabBaseModel(),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr),
                GroupName(src.GroupName),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            GroupWithRoles(const rapidjson::Value& obj) : GroupWithRoles()
            {
                readFromValue(obj);
            }

            ~GroupWithRoles()
            {
                if (Group != nullptr) delete Group;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!Roles.empty()) {
                    writer.String("Roles");
                    writer.StartArray();
                    for (auto iter = Roles.begin(); iter != Roles.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
                if (Roles_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Roles_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Roles.push_back(GroupRole(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct InitiateFileUploadMetadata : public PlayFabBaseModel
        {
            AZStd::string FileName;
            AZStd::string UploadUrl;

            InitiateFileUploadMetadata() :
                PlayFabBaseModel(),
                FileName(),
                UploadUrl()
            {}

            InitiateFileUploadMetadata(const InitiateFileUploadMetadata& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                UploadUrl(src.UploadUrl)
            {}

            InitiateFileUploadMetadata(const rapidjson::Value& obj) : InitiateFileUploadMetadata()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadMetadata()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (FileName.length() > 0) {
                    writer.String("FileName");
                    writer.String(FileName.c_str());
                }
                if (UploadUrl.length() > 0) {
                    writer.String("UploadUrl");
                    writer.String(UploadUrl.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
                if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
                const Value::ConstMemberIterator UploadUrl_member = obj.FindMember("UploadUrl");
                if (UploadUrl_member != obj.MemberEnd() && !UploadUrl_member->value.IsNull()) UploadUrl = UploadUrl_member->value.GetString();

                return true;
            }
        };

        struct InitiateFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<AZStd::string> FileNames; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalInt32 ProfileVersion;

            InitiateFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            InitiateFileUploadsRequest(const InitiateFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            InitiateFileUploadsRequest(const rapidjson::Value& obj) : InitiateFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("FileNames");
                writer.StartArray();
                for (auto iter = FileNames.begin(); iter != FileNames.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                if (ProfileVersion.notNull()) {
                    writer.String("ProfileVersion");
                    writer.Int(ProfileVersion);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
                if (FileNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FileNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FileNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

                return true;
            }
        };

        struct InitiateFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;
            AZStd::vector<InitiateFileUploadMetadata> UploadDetails; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            InitiateFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(nullptr),
                ProfileVersion(0),
                UploadDetails()
            {}

            InitiateFileUploadsResponse(const InitiateFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr),
                ProfileVersion(src.ProfileVersion),
                UploadDetails(src.UploadDetails)
            {}

            InitiateFileUploadsResponse(const rapidjson::Value& obj) : InitiateFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadsResponse()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!UploadDetails.empty()) {
                    writer.String("UploadDetails");
                    writer.StartArray();
                    for (auto iter = UploadDetails.begin(); iter != UploadDetails.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator UploadDetails_member = obj.FindMember("UploadDetails");
                if (UploadDetails_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UploadDetails_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UploadDetails.push_back(InitiateFileUploadMetadata(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct InviteToGroupRequest : public PlayFabBaseModel
        {
            OptionalBool AutoAcceptOutstandingApplication;
            EntityKey Entity;
            EntityKey Group;
            AZStd::string RoleId;

            InviteToGroupRequest() :
                PlayFabBaseModel(),
                AutoAcceptOutstandingApplication(),
                Entity(),
                Group(),
                RoleId()
            {}

            InviteToGroupRequest(const InviteToGroupRequest& src) :
                PlayFabBaseModel(),
                AutoAcceptOutstandingApplication(src.AutoAcceptOutstandingApplication),
                Entity(src.Entity),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            InviteToGroupRequest(const rapidjson::Value& obj) : InviteToGroupRequest()
            {
                readFromValue(obj);
            }

            ~InviteToGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AutoAcceptOutstandingApplication.notNull()) {
                    writer.String("AutoAcceptOutstandingApplication");
                    writer.Bool(AutoAcceptOutstandingApplication);
                }
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AutoAcceptOutstandingApplication_member = obj.FindMember("AutoAcceptOutstandingApplication");
                if (AutoAcceptOutstandingApplication_member != obj.MemberEnd() && !AutoAcceptOutstandingApplication_member->value.IsNull()) AutoAcceptOutstandingApplication = AutoAcceptOutstandingApplication_member->value.GetBool();
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct InviteToGroupResponse : public PlayFabBaseModel
        {
            time_t Expires;
            EntityKey* Group;
            EntityWithLineage* InvitedByEntity;
            EntityWithLineage* InvitedEntity;
            AZStd::string RoleId;

            InviteToGroupResponse() :
                PlayFabBaseModel(),
                Expires(0),
                Group(nullptr),
                InvitedByEntity(nullptr),
                InvitedEntity(nullptr),
                RoleId()
            {}

            InviteToGroupResponse(const InviteToGroupResponse& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : nullptr),
                InvitedByEntity(src.InvitedByEntity ? new EntityWithLineage(*src.InvitedByEntity) : nullptr),
                InvitedEntity(src.InvitedEntity ? new EntityWithLineage(*src.InvitedEntity) : nullptr),
                RoleId(src.RoleId)
            {}

            InviteToGroupResponse(const rapidjson::Value& obj) : InviteToGroupResponse()
            {
                readFromValue(obj);
            }

            ~InviteToGroupResponse()
            {
                if (Group != nullptr) delete Group;
                if (InvitedByEntity != nullptr) delete InvitedByEntity;
                if (InvitedEntity != nullptr) delete InvitedEntity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Expires");
                writeDatetime(Expires, writer);
                if (Group != nullptr) {
                    writer.String("Group");
                    Group->writeJSON(writer);
                }
                if (InvitedByEntity != nullptr) {
                    writer.String("InvitedByEntity");
                    InvitedByEntity->writeJSON(writer);
                }
                if (InvitedEntity != nullptr) {
                    writer.String("InvitedEntity");
                    InvitedEntity->writeJSON(writer);
                }
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
                const Value::ConstMemberIterator InvitedByEntity_member = obj.FindMember("InvitedByEntity");
                if (InvitedByEntity_member != obj.MemberEnd() && !InvitedByEntity_member->value.IsNull()) InvitedByEntity = new EntityWithLineage(InvitedByEntity_member->value);
                const Value::ConstMemberIterator InvitedEntity_member = obj.FindMember("InvitedEntity");
                if (InvitedEntity_member != obj.MemberEnd() && !InvitedEntity_member->value.IsNull()) InvitedEntity = new EntityWithLineage(InvitedEntity_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct IsMemberRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;
            AZStd::string RoleId;

            IsMemberRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group(),
                RoleId()
            {}

            IsMemberRequest(const IsMemberRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            IsMemberRequest(const rapidjson::Value& obj) : IsMemberRequest()
            {
                readFromValue(obj);
            }

            ~IsMemberRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct IsMemberResponse : public PlayFabBaseModel
        {
            bool IsMember;

            IsMemberResponse() :
                PlayFabBaseModel(),
                IsMember(false)
            {}

            IsMemberResponse(const IsMemberResponse& src) :
                PlayFabBaseModel(),
                IsMember(src.IsMember)
            {}

            IsMemberResponse(const rapidjson::Value& obj) : IsMemberResponse()
            {
                readFromValue(obj);
            }

            ~IsMemberResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("IsMember");
                writer.Bool(IsMember);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IsMember_member = obj.FindMember("IsMember");
                if (IsMember_member != obj.MemberEnd() && !IsMember_member->value.IsNull()) IsMember = IsMember_member->value.GetBool();

                return true;
            }
        };

        struct ListGroupApplicationsRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupApplicationsRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupApplicationsRequest(const ListGroupApplicationsRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupApplicationsRequest(const rapidjson::Value& obj) : ListGroupApplicationsRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupApplicationsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ListGroupApplicationsResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupApplication> Applications; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListGroupApplicationsResponse() :
                PlayFabBaseModel(),
                Applications()
            {}

            ListGroupApplicationsResponse(const ListGroupApplicationsResponse& src) :
                PlayFabBaseModel(),
                Applications(src.Applications)
            {}

            ListGroupApplicationsResponse(const rapidjson::Value& obj) : ListGroupApplicationsResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupApplicationsResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Applications.empty()) {
                    writer.String("Applications");
                    writer.StartArray();
                    for (auto iter = Applications.begin(); iter != Applications.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Applications_member = obj.FindMember("Applications");
                if (Applications_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Applications_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Applications.push_back(GroupApplication(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListGroupBlocksRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupBlocksRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupBlocksRequest(const ListGroupBlocksRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupBlocksRequest(const rapidjson::Value& obj) : ListGroupBlocksRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupBlocksRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ListGroupBlocksResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupBlock> BlockedEntities; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListGroupBlocksResponse() :
                PlayFabBaseModel(),
                BlockedEntities()
            {}

            ListGroupBlocksResponse(const ListGroupBlocksResponse& src) :
                PlayFabBaseModel(),
                BlockedEntities(src.BlockedEntities)
            {}

            ListGroupBlocksResponse(const rapidjson::Value& obj) : ListGroupBlocksResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupBlocksResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!BlockedEntities.empty()) {
                    writer.String("BlockedEntities");
                    writer.StartArray();
                    for (auto iter = BlockedEntities.begin(); iter != BlockedEntities.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BlockedEntities_member = obj.FindMember("BlockedEntities");
                if (BlockedEntities_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BlockedEntities_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BlockedEntities.push_back(GroupBlock(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListGroupInvitationsRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupInvitationsRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupInvitationsRequest(const ListGroupInvitationsRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupInvitationsRequest(const rapidjson::Value& obj) : ListGroupInvitationsRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupInvitationsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ListGroupInvitationsResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupInvitation> Invitations; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListGroupInvitationsResponse() :
                PlayFabBaseModel(),
                Invitations()
            {}

            ListGroupInvitationsResponse(const ListGroupInvitationsResponse& src) :
                PlayFabBaseModel(),
                Invitations(src.Invitations)
            {}

            ListGroupInvitationsResponse(const rapidjson::Value& obj) : ListGroupInvitationsResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupInvitationsResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Invitations.empty()) {
                    writer.String("Invitations");
                    writer.StartArray();
                    for (auto iter = Invitations.begin(); iter != Invitations.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Invitations_member = obj.FindMember("Invitations");
                if (Invitations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Invitations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Invitations.push_back(GroupInvitation(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListGroupMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupMembersRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupMembersRequest(const ListGroupMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupMembersRequest(const rapidjson::Value& obj) : ListGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct ListGroupMembersResponse : public PlayFabBaseModel
        {
            AZStd::vector<EntityMemberRole> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListGroupMembersResponse() :
                PlayFabBaseModel(),
                Members()
            {}

            ListGroupMembersResponse(const ListGroupMembersResponse& src) :
                PlayFabBaseModel(),
                Members(src.Members)
            {}

            ListGroupMembersResponse(const rapidjson::Value& obj) : ListGroupMembersResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupMembersResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Members.empty()) {
                    writer.String("Members");
                    writer.StartArray();
                    for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityMemberRole(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListMembershipOpportunitiesRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            ListMembershipOpportunitiesRequest() :
                PlayFabBaseModel(),
                Entity(nullptr)
            {}

            ListMembershipOpportunitiesRequest(const ListMembershipOpportunitiesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr)
            {}

            ListMembershipOpportunitiesRequest(const rapidjson::Value& obj) : ListMembershipOpportunitiesRequest()
            {
                readFromValue(obj);
            }

            ~ListMembershipOpportunitiesRequest()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

                return true;
            }
        };

        struct ListMembershipOpportunitiesResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupApplication> Applications; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<GroupInvitation> Invitations; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListMembershipOpportunitiesResponse() :
                PlayFabBaseModel(),
                Applications(),
                Invitations()
            {}

            ListMembershipOpportunitiesResponse(const ListMembershipOpportunitiesResponse& src) :
                PlayFabBaseModel(),
                Applications(src.Applications),
                Invitations(src.Invitations)
            {}

            ListMembershipOpportunitiesResponse(const rapidjson::Value& obj) : ListMembershipOpportunitiesResponse()
            {
                readFromValue(obj);
            }

            ~ListMembershipOpportunitiesResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Applications.empty()) {
                    writer.String("Applications");
                    writer.StartArray();
                    for (auto iter = Applications.begin(); iter != Applications.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Invitations.empty()) {
                    writer.String("Invitations");
                    writer.StartArray();
                    for (auto iter = Invitations.begin(); iter != Invitations.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Applications_member = obj.FindMember("Applications");
                if (Applications_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Applications_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Applications.push_back(GroupApplication(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Invitations_member = obj.FindMember("Invitations");
                if (Invitations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Invitations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Invitations.push_back(GroupInvitation(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListMembershipRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            ListMembershipRequest() :
                PlayFabBaseModel(),
                Entity(nullptr)
            {}

            ListMembershipRequest(const ListMembershipRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : nullptr)
            {}

            ListMembershipRequest(const rapidjson::Value& obj) : ListMembershipRequest()
            {
                readFromValue(obj);
            }

            ~ListMembershipRequest()
            {
                if (Entity != nullptr) delete Entity;
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (Entity != nullptr) {
                    writer.String("Entity");
                    Entity->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

                return true;
            }
        };

        struct ListMembershipResponse : public PlayFabBaseModel
        {
            AZStd::vector<GroupWithRoles> Groups; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListMembershipResponse() :
                PlayFabBaseModel(),
                Groups()
            {}

            ListMembershipResponse(const ListMembershipResponse& src) :
                PlayFabBaseModel(),
                Groups(src.Groups)
            {}

            ListMembershipResponse(const rapidjson::Value& obj) : ListMembershipResponse()
            {
                readFromValue(obj);
            }

            ~ListMembershipResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Groups.empty()) {
                    writer.String("Groups");
                    writer.StartArray();
                    for (auto iter = Groups.begin(); iter != Groups.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Groups_member = obj.FindMember("Groups");
                if (Groups_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Groups_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Groups.push_back(GroupWithRoles(memberList[i]));
                    }
                }

                return true;
            }
        };

        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        inline void writeOperationTypesEnumJSON(OperationTypes enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case OperationTypesCreated: writer.String("Created"); break;
            case OperationTypesUpdated: writer.String("Updated"); break;
            case OperationTypesDeleted: writer.String("Deleted"); break;
            case OperationTypesNone: writer.String("None"); break;

            }
        }

        inline OperationTypes readOperationTypesFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<OperationTypes>(obj.GetInt());

            static std::map<const char *, OperationTypes, PlayFabClientSdk::StringCompare> _OperationTypesMap;
            if (_OperationTypesMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _OperationTypesMap["Created"] = OperationTypesCreated;
                _OperationTypesMap["Updated"] = OperationTypesUpdated;
                _OperationTypesMap["Deleted"] = OperationTypesDeleted;
                _OperationTypesMap["None"] = OperationTypesNone;

            }

            auto output = _OperationTypesMap.find(obj.GetString());
            if (output != _OperationTypesMap.end())
                return output->second;

            return OperationTypesCreated; // Basically critical fail
        }

        struct RemoveGroupApplicationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            RemoveGroupApplicationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            RemoveGroupApplicationRequest(const RemoveGroupApplicationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            RemoveGroupApplicationRequest(const rapidjson::Value& obj) : RemoveGroupApplicationRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGroupApplicationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct RemoveGroupInvitationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            RemoveGroupInvitationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            RemoveGroupInvitationRequest(const RemoveGroupInvitationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            RemoveGroupInvitationRequest(const rapidjson::Value& obj) : RemoveGroupInvitationRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGroupInvitationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct RemoveMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            AZStd::vector<EntityKey> Members; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string RoleId;

            RemoveMembersRequest() :
                PlayFabBaseModel(),
                Group(),
                Members(),
                RoleId()
            {}

            RemoveMembersRequest(const RemoveMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                Members(src.Members),
                RoleId(src.RoleId)
            {}

            RemoveMembersRequest(const rapidjson::Value& obj) : RemoveMembersRequest()
            {
                readFromValue(obj);
            }

            ~RemoveMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Group");
                Group.writeJSON(writer);
                writer.String("Members");
                writer.StartArray();
                for (auto iter = Members.begin(); iter != Members.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(EntityKey(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

                return true;
            }
        };

        struct SetEntityProfilePolicyRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            AZStd::vector<EntityPermissionStatement> Statements; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetEntityProfilePolicyRequest() :
                PlayFabBaseModel(),
                Entity(),
                Statements()
            {}

            SetEntityProfilePolicyRequest(const SetEntityProfilePolicyRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Statements(src.Statements)
            {}

            SetEntityProfilePolicyRequest(const rapidjson::Value& obj) : SetEntityProfilePolicyRequest()
            {
                readFromValue(obj);
            }

            ~SetEntityProfilePolicyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                if (!Statements.empty()) {
                    writer.String("Statements");
                    writer.StartArray();
                    for (auto iter = Statements.begin(); iter != Statements.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Statements_member = obj.FindMember("Statements");
                if (Statements_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statements_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statements.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct SetEntityProfilePolicyResponse : public PlayFabBaseModel
        {
            AZStd::vector<EntityPermissionStatement> Permissions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetEntityProfilePolicyResponse() :
                PlayFabBaseModel(),
                Permissions()
            {}

            SetEntityProfilePolicyResponse(const SetEntityProfilePolicyResponse& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            SetEntityProfilePolicyResponse(const rapidjson::Value& obj) : SetEntityProfilePolicyResponse()
            {
                readFromValue(obj);
            }

            ~SetEntityProfilePolicyResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Permissions.empty()) {
                    writer.String("Permissions");
                    writer.StartArray();
                    for (auto iter = Permissions.begin(); iter != Permissions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
                if (Permissions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Permissions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Permissions.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct SetGlobalPolicyRequest : public PlayFabBaseModel
        {
            AZStd::vector<EntityPermissionStatement> Permissions; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetGlobalPolicyRequest() :
                PlayFabBaseModel(),
                Permissions()
            {}

            SetGlobalPolicyRequest(const SetGlobalPolicyRequest& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            SetGlobalPolicyRequest(const rapidjson::Value& obj) : SetGlobalPolicyRequest()
            {
                readFromValue(obj);
            }

            ~SetGlobalPolicyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (!Permissions.empty()) {
                    writer.String("Permissions");
                    writer.StartArray();
                    for (auto iter = Permissions.begin(); iter != Permissions.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
                if (Permissions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Permissions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Permissions.push_back(EntityPermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct SetGlobalPolicyResponse : public PlayFabBaseModel
        {

            SetGlobalPolicyResponse() :
                PlayFabBaseModel()
            {}

            SetGlobalPolicyResponse(const SetGlobalPolicyResponse& src) :
                PlayFabBaseModel()
            {}

            SetGlobalPolicyResponse(const rapidjson::Value& obj) : SetGlobalPolicyResponse()
            {
                readFromValue(obj);
            }

            ~SetGlobalPolicyResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetObject : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            OptionalBool DeleteObject;
            AZStd::string EscapedDataObject;
            AZStd::string ObjectName;

            SetObject() :
                PlayFabBaseModel(),
                DataObject(),
                DeleteObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            SetObject(const SetObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                DeleteObject(src.DeleteObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            SetObject(const rapidjson::Value& obj) : SetObject()
            {
                readFromValue(obj);
            }

            ~SetObject()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (DataObject.notNull()) {
                    writer.String("DataObject");
                    DataObject.writeJSON(writer);
                }
                if (DeleteObject.notNull()) {
                    writer.String("DeleteObject");
                    writer.Bool(DeleteObject);
                }
                if (EscapedDataObject.length() > 0) {
                    writer.String("EscapedDataObject");
                    writer.String(EscapedDataObject.c_str());
                }
                writer.String("ObjectName");
                writer.String(ObjectName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataObject_member = obj.FindMember("DataObject");
                if (DataObject_member != obj.MemberEnd() && !DataObject_member->value.IsNull()) DataObject = MultitypeVar(DataObject_member->value);
                const Value::ConstMemberIterator DeleteObject_member = obj.FindMember("DeleteObject");
                if (DeleteObject_member != obj.MemberEnd() && !DeleteObject_member->value.IsNull()) DeleteObject = DeleteObject_member->value.GetBool();
                const Value::ConstMemberIterator EscapedDataObject_member = obj.FindMember("EscapedDataObject");
                if (EscapedDataObject_member != obj.MemberEnd() && !EscapedDataObject_member->value.IsNull()) EscapedDataObject = EscapedDataObject_member->value.GetString();
                const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
                if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();

                return true;
            }
        };

        struct SetObjectInfo : public PlayFabBaseModel
        {
            AZStd::string ObjectName;
            AZStd::string OperationReason;
            Boxed<OperationTypes> SetResult;

            SetObjectInfo() :
                PlayFabBaseModel(),
                ObjectName(),
                OperationReason(),
                SetResult()
            {}

            SetObjectInfo(const SetObjectInfo& src) :
                PlayFabBaseModel(),
                ObjectName(src.ObjectName),
                OperationReason(src.OperationReason),
                SetResult(src.SetResult)
            {}

            SetObjectInfo(const rapidjson::Value& obj) : SetObjectInfo()
            {
                readFromValue(obj);
            }

            ~SetObjectInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ObjectName.length() > 0) {
                    writer.String("ObjectName");
                    writer.String(ObjectName.c_str());
                }
                if (OperationReason.length() > 0) {
                    writer.String("OperationReason");
                    writer.String(OperationReason.c_str());
                }
                if (SetResult.notNull()) {
                    writer.String("SetResult");
                    writeOperationTypesEnumJSON(SetResult, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
                if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();
                const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
                if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
                const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
                if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

                return true;
            }
        };

        struct SetObjectsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            OptionalInt32 ExpectedProfileVersion;
            AZStd::vector<SetObject> Objects; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetObjectsRequest() :
                PlayFabBaseModel(),
                Entity(),
                ExpectedProfileVersion(),
                Objects()
            {}

            SetObjectsRequest(const SetObjectsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Objects(src.Objects)
            {}

            SetObjectsRequest(const rapidjson::Value& obj) : SetObjectsRequest()
            {
                readFromValue(obj);
            }

            ~SetObjectsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                if (ExpectedProfileVersion.notNull()) {
                    writer.String("ExpectedProfileVersion");
                    writer.Int(ExpectedProfileVersion);
                }
                writer.String("Objects");
                writer.StartArray();
                for (auto iter = Objects.begin(); iter != Objects.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
                if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
                if (Objects_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Objects_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Objects.push_back(SetObject(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct SetObjectsResponse : public PlayFabBaseModel
        {
            Int32 ProfileVersion;
            AZStd::vector<SetObjectInfo> SetResults; // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetObjectsResponse() :
                PlayFabBaseModel(),
                ProfileVersion(0),
                SetResults()
            {}

            SetObjectsResponse(const SetObjectsResponse& src) :
                PlayFabBaseModel(),
                ProfileVersion(src.ProfileVersion),
                SetResults(src.SetResults)
            {}

            SetObjectsResponse(const rapidjson::Value& obj) : SetObjectsResponse()
            {
                readFromValue(obj);
            }

            ~SetObjectsResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (!SetResults.empty()) {
                    writer.String("SetResults");
                    writer.StartArray();
                    for (auto iter = SetResults.begin(); iter != SetResults.end(); iter++) {     // #THIRD_KIND_PLAYFAB_BEHAVIOUR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator SetResults_member = obj.FindMember("SetResults");
                if (SetResults_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = SetResults_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        SetResults.push_back(SetObjectInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UnblockEntityRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            UnblockEntityRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            UnblockEntityRequest(const UnblockEntityRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            UnblockEntityRequest(const rapidjson::Value& obj) : UnblockEntityRequest()
            {
                readFromValue(obj);
            }

            ~UnblockEntityRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                writer.String("Entity");
                Entity.writeJSON(writer);
                writer.String("Group");
                Group.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
                if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

                return true;
            }
        };

        struct UpdateGroupRequest : public PlayFabBaseModel
        {
            AZStd::string AdminRoleId;
            OptionalInt32 ExpectedProfileVersion;
            EntityKey Group;
            AZStd::string GroupName;
            AZStd::string MemberRoleId;

            UpdateGroupRequest() :
                PlayFabBaseModel(),
                AdminRoleId(),
                ExpectedProfileVersion(),
                Group(),
                GroupName(),
                MemberRoleId()
            {}

            UpdateGroupRequest(const UpdateGroupRequest& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId)
            {}

            UpdateGroupRequest(const rapidjson::Value& obj) : UpdateGroupRequest()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (AdminRoleId.length() > 0) {
                    writer.String("AdminRoleId");
                    writer.String(AdminRoleId.c_str());
                }
                if (ExpectedProfileVersion.notNull()) {
                    writer.String("ExpectedProfileVersion");
                    writer.Int(ExpectedProfileVersion);
                }
                writer.String("Group");
                Group.writeJSON(writer);
                if (GroupName.length() > 0) {
                    writer.String("GroupName");
                    writer.String(GroupName.c_str());
                }
                if (MemberRoleId.length() > 0) {
                    writer.String("MemberRoleId");
                    writer.String(MemberRoleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
                if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
                const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
                if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
                if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
                const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
                if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();

                return true;
            }
        };

        struct UpdateGroupResponse : public PlayFabBaseModel
        {
            AZStd::string OperationReason;
            Int32 ProfileVersion;
            Boxed<OperationTypes> SetResult;

            UpdateGroupResponse() :
                PlayFabBaseModel(),
                OperationReason(),
                ProfileVersion(0),
                SetResult()
            {}

            UpdateGroupResponse(const UpdateGroupResponse& src) :
                PlayFabBaseModel(),
                OperationReason(src.OperationReason),
                ProfileVersion(src.ProfileVersion),
                SetResult(src.SetResult)
            {}

            UpdateGroupResponse(const rapidjson::Value& obj) : UpdateGroupResponse()
            {
                readFromValue(obj);
            }

            ~UpdateGroupResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (OperationReason.length() > 0) {
                    writer.String("OperationReason");
                    writer.String(OperationReason.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (SetResult.notNull()) {
                    writer.String("SetResult");
                    writeOperationTypesEnumJSON(SetResult, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
                if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
                if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

                return true;
            }
        };

        struct UpdateGroupRoleRequest : public PlayFabBaseModel
        {
            OptionalInt32 ExpectedProfileVersion;
            EntityKey Group;
            AZStd::string RoleId;
            AZStd::string RoleName;

            UpdateGroupRoleRequest() :
                PlayFabBaseModel(),
                ExpectedProfileVersion(),
                Group(),
                RoleId(),
                RoleName()
            {}

            UpdateGroupRoleRequest(const UpdateGroupRoleRequest& src) :
                PlayFabBaseModel(),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Group(src.Group),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            UpdateGroupRoleRequest(const rapidjson::Value& obj) : UpdateGroupRoleRequest()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRoleRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (ExpectedProfileVersion.notNull()) {
                    writer.String("ExpectedProfileVersion");
                    writer.Int(ExpectedProfileVersion);
                }
                writer.String("Group");
                Group.writeJSON(writer);
                if (RoleId.length() > 0) {
                    writer.String("RoleId");
                    writer.String(RoleId.c_str());
                }
                writer.String("RoleName");
                writer.String(RoleName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
                if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
                if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
                const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
                if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
                const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
                if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

                return true;
            }
        };

        struct UpdateGroupRoleResponse : public PlayFabBaseModel
        {
            AZStd::string OperationReason;
            Int32 ProfileVersion;
            Boxed<OperationTypes> SetResult;

            UpdateGroupRoleResponse() :
                PlayFabBaseModel(),
                OperationReason(),
                ProfileVersion(0),
                SetResult()
            {}

            UpdateGroupRoleResponse(const UpdateGroupRoleResponse& src) :
                PlayFabBaseModel(),
                OperationReason(src.OperationReason),
                ProfileVersion(src.ProfileVersion),
                SetResult(src.SetResult)
            {}

            UpdateGroupRoleResponse(const rapidjson::Value& obj) : UpdateGroupRoleResponse()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRoleResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) const override
            {
                writer.StartObject();
                if (OperationReason.length() > 0) {
                    writer.String("OperationReason");
                    writer.String(OperationReason.c_str());
                }
                writer.String("ProfileVersion");
                writer.Int(ProfileVersion);
                if (SetResult.notNull()) {
                    writer.String("SetResult");
                    writeOperationTypesEnumJSON(SetResult, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
                if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
                const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
                if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
                const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
                if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

                return true;
            }
        };


    }
}
