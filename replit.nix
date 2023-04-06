{ pkgs }: {
	deps = [
    pkgs.gnumake42
    pkgs.sudo
    pkgs.mk
    pkgs.aspell
    pkgs.aspellDicts.en
    pkgs.clang_12
		pkgs.cmake
		pkgs.gdb
    pkgs.boost
	];
}