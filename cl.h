#ifndef MRIM_CL_H
 #define MRIM_CL_H
 #include "mrim.h"
 #include "proto.h"
 #include "package.h"
 #include "mrim-util.h"
 
 #define MRIM_NO_GROUP 12345

static const gchar *zodiac[]={
		N_("Aries"),
		N_("Taurus"),
		N_("Gemini"),
		N_("Cancer"),
		N_("Leo"),
		N_("Virgo"),
		N_("Libra"),
		N_("Scorpius"),
		N_("Sagittarius"),
		N_("Capricornus"), // 10 in mrim, 9 in massive
		N_("Aquaruis"),
		N_("Pisces")
};

static const int info_header_size = 5;

static const gchar *info_header[]={
		"Nickname",
		"FirstName",
		"LastName",
		"Birthday",
		"Phone"
};

static const gchar *info_header_i18n[]={
		N_("Nickname"),
		N_("FirstName"),
		N_("LastName"),
		N_("Birthday"),
		N_("Phone")
};

//	Buddy list
void mrim_cl_load(PurpleConnection *gc, mrim_data *mrim, package *pack);

//	Groups
void mrim_add_group(mrim_data *mrim, char *name);
void mrim_rename_group(PurpleConnection *gc, const char *old_name,PurpleGroup *group, GList *moved_buddies);
void mrim_remove_group(PurpleConnection *gc, PurpleGroup *group);
void mg_add(guint32 flags, gchar *name, guint id, mrim_data *mrim);
PurpleGroup *get_mrim_group_by_id(mrim_data *mrim, guint32 id);
guint32 get_mrim_group_id_by_name(mrim_data *mrim, gchar *name);

//	Buddies
void mrim_add_buddy(PurpleConnection *gc, PurpleBuddy *buddy, PurpleGroup *group);
void mrim_remove_buddy(PurpleConnection *gc, PurpleBuddy *buddy, PurpleGroup *group);
void mrim_alias_buddy(PurpleConnection *gc, const char *who, const char *alias);
void mrim_move_buddy(PurpleConnection *gc, const char *who, const char *old_group, const char *new_group);
void free_buddy(PurpleBuddy *buddy);
void free_buddy_proto_data(mrim_buddy *mb);

//	Userpics
void mrim_fetch_avatar(PurpleBuddy *buddy);
void mrim_avatar_cb(PurpleUtilFetchUrlData *url_data, gpointer user_data, const gchar *url_text, gsize len, const gchar *error_message);

//	Authorization
void mrim_authorization_yes(void *va_data);
void mrim_authorization_no(void *va_data);

//	PQ. The Pending Queue // Pawn-Queen =))
//   Implemented to track pending actions.
void mrim_sms_ack(mrim_data *mrim ,package *pack);
void mrim_add_contact_ack(mrim_data *mrim ,package *pack);
void mrim_modify_contact_ack(mrim_data *mrim ,package *pack);
void mrim_mpop_session(mrim_data *mrim ,package *pack);
void mrim_anketa_info(mrim_data *mrim, package *pack);
void pq_free_element(gpointer data);
void mg_free_element(gpointer data);

void print_cl_status(guint32 status);

void send_package_authorize(mrim_data *mrim, gchar *to, gchar *who);

void mrim_searchresults_add_buddy(PurpleConnection *gc, GList *row, void *user_data);

gchar *mrim_phones_to_string(gchar **phones);

void mrim_pkt_modify_buddy(mrim_data *mrim, PurpleBuddy *buddy, guint32 seq);
void mrim_pkt_modify_group(mrim_data *mrim, guint32 group_id, gchar *group_name, guint32 flags);
void mrim_pkt_add_group(mrim_data *mrim, gchar *group_name, guint32 seq);
#endif
