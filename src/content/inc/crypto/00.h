/* List based upon the items created for use in an active Crypto App on a person's device -- from 01.json */

/*
    char * crypto_id;
    char * crypto_fname;
    char * crypto_lname;
    char * crypto_company_name;
    char * crypto_company_initials;
    char * crypto_private_key_hash;
    char * crypto_private_key_qr;
    char * crypto_public_key_hash;
    char * crypto_public_key_qr;
    char * crypto_ticker_symbol;
    double crypto_balance;
    double crypto_value;
    double crypto_price;
    char * crypto_type;
    char * crypto_vendor;
    char * crypto_notes;
    const lv_img_dsc_t * crypto_icon_logo;
*/


/* Create and initialize the Crypto_00 list */
static crypto_item crypto_00_list[] = {
    {
        .crypto_id = "0001",
        .crypto_company_name = "Bitcoin",
        .crypto_company_initials = "BTC",
        .crypto_fname = "",
        .crypto_lname = "",
        .crypto_private_key_hash = "Kzf2szsXbFr7AgYUNuazuMmsihud7pYPdYtMSuL3GkbbasXXfqyT",
        .crypto_public_key_hash = "1MxttQc9iQLyoh1wF5maFLNa7jCtuz3Rzo",
        .crypto_ticker_symbol = "btc",
        .crypto_balance = 6.76168627,
        .crypto_value = 439001.00,
        .crypto_price = 1.7876543456789765567,
        .crypto_icon_logo = &Icon_Crypto_Bitcoin_Yellow
    },
    {
        .crypto_id = "0002",
        .crypto_company_name = "Ethereum",
        .crypto_company_initials = "ETH",
        .crypto_fname = "",
        .crypto_lname = "",
        .crypto_private_key_hash = "1E99423A4ED27608A15A2616A2B0E9E52CED330AC530EDCC32C8FFC6A526AEDD",
        .crypto_public_key_hash = "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa",
        .crypto_ticker_symbol = "eth",
        .crypto_balance = 38.96362028,
        .crypto_value = 123345.87,
        .crypto_price = 1.7876543456789765567,
        .crypto_icon_logo = &Icon_Crypto_Ethereum_Yellow
    },
    {
        .crypto_id = "0003",
        .crypto_company_name = "Tether USDt",
        .crypto_company_initials = "USDT",
        .crypto_fname = "",
        .crypto_lname = "",
        .crypto_private_key_hash = "L1jzi3mprBPaFVSMmYHWK1A37zb5QA5rN8aUtqX5WWYdYa4JS2JL",
        .crypto_public_key_hash = "16ZuUbNLLSLSEqbZ2MnhSJErvpBseNxbwa",
        .crypto_ticker_symbol = "usdt",
        .crypto_balance = 275950,
        .crypto_value = 275901.43,
        .crypto_price = 1.7876543456789765567,
        .crypto_icon_logo = &Icon_Crypto_Tether_Yellow
    },
    {
        .crypto_id = "0004",
        .crypto_company_name = "Binance",
        .crypto_company_initials = "BNB",
        .crypto_fname = "",
        .crypto_lname = "",
        .crypto_private_key_hash = "KwK3JE2nhZX6PYA17QeoS5fgxzr6pL38RRC4sNDd8SGfeLxRra6Y",
        .crypto_public_key_hash = "1JZqqrcGTQwwYzd1fAWUpnbjY6Zmo4BifY",
        .crypto_ticker_symbol = "bnb",
        .crypto_balance = 1667,
        .crypto_value = 948271.20,
        .crypto_price = 1.7876543456789765567,
        .crypto_icon_logo = &Icon_Crypto_Binance_Yellow
    },
    {
        .crypto_id = "end",
        .crypto_notes = "TAP HERE\nTo import\nyour Contacts",
    },
};