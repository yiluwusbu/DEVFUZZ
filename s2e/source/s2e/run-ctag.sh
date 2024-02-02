#!/bin/bash

scope_file=".scopefile"
tag_file="tags"

codedir=(
.
)

function gen_scope
{
    > ${scope_file}
    for d in ${codedir[@]}; do
        find $d -type f \
            -a \( -name "*.h" -o -name "*.hpp" -o -name "*.cpp" -o -name "*.c" \
            -o -name "*.cc" \) >> ${scope_file}
    done
    rm -f scope.* ${tag_file}
    ctags -I "__THROW __nonnull __attribute_pure__ __attribute__ G_GNUC_PRINTF+" \
    --file-scope=yes --c++-kinds=+px --c-kinds=+px --fields=+iaS -Ra --extra=+fq \
    --langmap=c:.c.h.pc.ec --languages=c,c++ --links=yes \
    -f ${tag_file} -L ${scope_file}
    cscope -Rb -i ${scope_file}
}

gen_scope

