drop table if exists "log";
CREATE TABLE "log" (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	message TEXT NOT NULL,
	"scope" TEXT,
	subject INTEGER,
	create_ts datetime DEFAULT current_timestamp
);

drop table if exists "session";
CREATE TABLE IF NOT EXISTS "session" (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    uuid text,
	"data" TEXT,
	create_ts datetime DEFAULT current_timestamp NOT NULL,
	update_ts datetime,
    expire_ts datetime
);

drop table if exists service;
create table if not exists "service" (
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    "name" TEXT,
    "type" TEXT,
    proto TEXT,
    port integer,
    is_active boolean,
    create_ts datetime DEFAULT current_timestamp NOT NULL,
    update_ts datetime
);

drop table if exists request_response;
CREATE TABLE request_response (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    "session_id" integer,
	service_id INTEGER,
	request_bytes BLOB,
	response_bytes BLOB,
	sender TEXT,
	recipient TEXT,
	create_ts datetime DEFAULT current_timestamp,
    update_ts datetime
);

drop table if exists data_chuck;
create table data_chunk (
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    data_bytes blob,
    chunk_sent integer,
    create_ts datetime DEFAULT current_timestamp

);

drop table if exists "queue";
create table "queue" (
   	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    "session_id" integer,
    data_bytes blob
    create_ts datetime DEFAULT current_timestamp,
    update_ts datetime
);
