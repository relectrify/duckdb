duckdb_extension_load(ducklake
    GIT_URL https://github.com/duckdb/ducklake
    GIT_TAG e6a3bd0a8554b74d97cbc7e8acc3e2c9f01a0385
)
duckdb_extension_load(httpfs
    GIT_URL https://github.com/duckdb/duckdb-httpfs
    GIT_TAG 52afb4204a3238d6ee132e83340f8d68c40ee91c
)
duckdb_extension_load(mysql_scanner
    GIT_URL https://github.com/duckdb/duckdb-mysql
    GIT_TAG 496ac9e3cb61bd8d6d1255f73cf69b958a311525
    SUBMODULES database-connector
    APPLY_PATCHES
)
duckdb_extension_load(postgres_scanner
    GIT_URL https://github.com/duckdb/duckdb-postgres
    GIT_TAG 6b2b12cad3afef61e8a4637e714e8a88895fed1a
    SUBMODULES database-connector
)
duckdb_extension_load(aws
    GIT_URL https://github.com/duckdb/duckdb-aws
    GIT_TAG 38d4ed30b7f5855168f4b494bf9be611c868c69a
)
duckdb_extension_load(quack
    GIT_URL https://github.com/duckdb/duckdb-quack
    GIT_TAG 1693647c152b438aa2a6a9ad71764f99c5a561e0
)
