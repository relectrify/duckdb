duckdb_extension_load(ducklake
    GIT_URL https://github.com/duckdb/ducklake
    GIT_TAG 7ea15644fd5f5ff42b86b8a703c14172acc7b8bd
)
duckdb_extension_load(httpfs
    GIT_URL https://github.com/duckdb/duckdb-httpfs
    GIT_TAG 74f954001f3a740c909181b02259de6c7b942632
    INCLUDE_DIR src/include
)
duckdb_extension_load(mysql_scanner
    GIT_URL https://github.com/duckdb/duckdb-mysql
    GIT_TAG 372a86f96f4735ed3a1c3bb2e50594a2d73bc143
)
duckdb_extension_load(postgres_scanner
    GIT_URL https://github.com/duckdb/duckdb-postgres
    GIT_TAG a42c490df0019406658073c003b7d89dd4338466
)
