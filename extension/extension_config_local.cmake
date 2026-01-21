duckdb_extension_load(ducklake
    GIT_URL https://github.com/duckdb/ducklake
    GIT_TAG 08089b16dc8a18ce04abb6efd87e25cb4d64803a
)
duckdb_extension_load(httpfs
    GIT_URL https://github.com/duckdb/duckdb-httpfs
    GIT_TAG f71cfdb4bff85b9e15b1f3b842d9aa395aff0167
)
duckdb_extension_load(mysql_scanner
    GIT_URL https://github.com/duckdb/duckdb-mysql
    GIT_TAG e04d8eef94c94e70c5d5663895610b1bb475d506
    SUBMODULES database-connector
    APPLY_PATCHES
)
duckdb_extension_load(postgres_scanner
    GIT_URL https://github.com/duckdb/duckdb-postgres
    GIT_TAG 8b9d0bbe8de4c57fb90d9e2530f9ce39f8c4baf3
    SUBMODULES database-connector
)
duckdb_extension_load(aws
    GIT_URL https://github.com/duckdb/duckdb-aws
    GIT_TAG 1b96925856ded7c9cbde7403fdb3d467d0cdf779
)
duckdb_extension_load(quack
    GIT_URL https://github.com/duckdb/duckdb-quack
    GIT_TAG 3bc63c01f80a13d57ca02a721dd13908c1d934c1
    SUBMODULES extension-ci-tools
)
