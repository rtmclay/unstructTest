                   unstructTest - a Test of parallel hdf5 routines on TACC systems
		       by Robert McLay


----------------------------------------------------------------------
Getting Started.
----------------------------------------------------------------------

1) Clone this repo
2) Load the phdf5 module
3) Run **make**
4) copy **unstructTest** to scratch
5) Create a batch job to run unstructTest

The options to unstructTest are:

 -h, -?        : Print Usage
 -v            : Print Version
 -R            : use ROMIO
 -C            : use h5 chunk
 -S            : use h5 slab (default)
 -I            : use independent instead of collective(collective is default)
 -O type       : output type (l: lua, t: table, b: both (default: table))
 -n nvar       : nvar  (default=4)
 -l num        : local size is num (default=10)
 -g num        : global size in GBytes
 -x num        : xwidth


Use the -g option to set global size.

