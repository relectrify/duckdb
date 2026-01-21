duckdb_extension_load(ducklake
    GIT_URL https://github.com/duckdb/ducklake
    GIT_TAG d318a545571d7d46eb751fa2aa5f6f4389285d3c
)
duckdb_extension_load(httpfs
    GIT_URL https://github.com/duckdb/duckdb-httpfs
    GIT_TAG c3f215ab360f04dc3d3d5305fa81849c0121f111
)
duckdb_extension_load(mysql_scanner
    GIT_URL https://github.com/duckdb/duckdb-mysql
    GIT_TAG 37006e53a58ddc31eeb96ff95c21f3196e27fcf2
    SUBMODULES database-connector
    APPLY_PATCHES
)
duckdb_extension_load(postgres_scanner
    GIT_URL https://github.com/duckdb/duckdb-postgres
    GIT_TAG 8f813f9b9c9e52a9074a050a0be60f49160a6baa
    SUBMODULES database-connector
)
duckdb_extension_load(aws
    GIT_URL https://github.com/duckdb/duckdb-aws
    GIT_TAG 08ad34f625e4a8e15221e462b96000ff29174447
)
duckdb_extension_load(quack
    GIT_URL https://github.com/duckdb/duckdb-quack
    GIT_TAG 40de7badae4193c29d9c0834473fb76acc6c51e6
)
