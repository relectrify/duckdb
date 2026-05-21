duckdb_extension_load(ducklake
    GIT_URL https://github.com/duckdb/ducklake
    GIT_TAG ac7595b0a1305bea3d4cfaca763b0ce964c763a2
)
duckdb_extension_load(httpfs
    GIT_URL https://github.com/duckdb/duckdb-httpfs
    GIT_TAG 4bc690dba4496c765777a0269d48fdbaff7cdc11
)
duckdb_extension_load(mysql_scanner
    GIT_URL https://github.com/duckdb/duckdb-mysql
    GIT_TAG 99c2e091b153b7f1cbd449988332232e75684b41
    SUBMODULES database-connector
    APPLY_PATCHES
)
duckdb_extension_load(postgres_scanner
    GIT_URL https://github.com/duckdb/duckdb-postgres
    GIT_TAG 318dabb2474fc3789b0199301a2e661e19c1b4fc
    SUBMODULES database-connector
    APPLY_PATCHES
)
duckdb_extension_load(aws
    GIT_URL https://github.com/duckdb/duckdb-aws
    GIT_TAG 28c853c084a6e3acd36d7b8018c42438bb8c5a33
)
duckdb_extension_load(quack
    GIT_URL https://github.com/duckdb/duckdb-quack
    GIT_TAG 7e80f7ffcc98d0b3e81d0e1df8cc1c2da240a64b
)
