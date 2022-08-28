
typedef struct {
    char * menu_name;
    void (* page_cb)(lv_event_t *);
} menu_dispatch;

void device_cb(lv_event_t *e);
void o_cb(lv_event_t *e);
void files_cb(lv_event_t *e);
void email_cb(lv_event_t *e);
void contacts_cb(lv_event_t *e);
void calendar_cb(lv_event_t *e);
void text_cb(lv_event_t *e);
void music_cb(lv_event_t *e);
void settings_cb(lv_event_t *e);