#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001250A0
// Address: 0x1250a0 - 0x1251a0
void sub_001250A0_0x1250a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001250A0_0x1250a0");
#endif

    switch (ctx->pc) {
        case 0x1250f4u: goto label_1250f4;
        case 0x12510cu: goto label_12510c;
        default: break;
    }

    ctx->pc = 0x1250a0u;

    // 0x1250a0: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x1250a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1250a4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1250a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1250a8: 0x2ca50004  sltiu       $a1, $a1, 0x4
    ctx->pc = 0x1250a8u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x1250ac: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1250acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1250b0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1250b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1250b4: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x1250b4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1250b8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1250b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1250bc: 0x140902d  daddu       $s2, $t2, $zero
    ctx->pc = 0x1250bcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1250c0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1250c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1250c4: 0x80582d  daddu       $t3, $a0, $zero
    ctx->pc = 0x1250c4u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1250c8: 0x100802d  daddu       $s0, $t0, $zero
    ctx->pc = 0x1250c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1250cc: 0x14a0002a  bnez        $a1, . + 4 + (0x2A << 2)
    ctx->pc = 0x1250CCu;
    {
        const bool branch_taken_0x1250cc = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1250D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1250CCu;
            // 0x1250d0: 0x30c600ff  andi        $a2, $a2, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1250cc) {
            ctx->pc = 0x125178u;
            goto label_125178;
        }
    }
    ctx->pc = 0x1250D4u;
    // 0x1250d4: 0x2cc20010  sltiu       $v0, $a2, 0x10
    ctx->pc = 0x1250d4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1250d8: 0x5440000f  bnel        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x1250D8u;
    {
        const bool branch_taken_0x1250d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1250d8) {
            ctx->pc = 0x1250DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1250D8u;
            // 0x1250dc: 0x2cc20008  sltiu       $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x125118u;
            goto label_125118;
        }
    }
    ctx->pc = 0x1250E0u;
    // 0x1250e0: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1250e0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1250e4: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x1250e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1250e8: 0x24a59bb0  addiu       $a1, $a1, -0x6450
    ctx->pc = 0x1250e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941616));
    // 0x1250ec: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1250ECu;
    SET_GPR_U32(ctx, 31, 0x1250F4u);
    ctx->pc = 0x1250F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1250ECu;
            // 0x1250f0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1250F4u; }
        if (ctx->pc != 0x1250F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1250F4u; }
        if (ctx->pc != 0x1250F4u) { return; }
    }
    ctx->pc = 0x1250F4u;
label_1250f4:
    // 0x1250f4: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1250f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1250f8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1250f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1250fc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1250fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125100: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x125100u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125104: 0xc049156  jal         func_124558
    ctx->pc = 0x125104u;
    SET_GPR_U32(ctx, 31, 0x12510Cu);
    ctx->pc = 0x125108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125104u;
            // 0x125108: 0x240402d  daddu       $t0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124558u;
    if (runtime->hasFunction(0x124558u)) {
        auto targetFn = runtime->lookupFunction(0x124558u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12510Cu; }
        if (ctx->pc != 0x12510Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124558_0x124558(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12510Cu; }
        if (ctx->pc != 0x12510Cu) { return; }
    }
    ctx->pc = 0x12510Cu;
label_12510c:
    // 0x12510c: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x12510Cu;
    {
        const bool branch_taken_0x12510c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12510Cu;
            // 0x125110: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12510c) {
            ctx->pc = 0x125188u;
            goto label_125188;
        }
    }
    ctx->pc = 0x125114u;
    // 0x125114: 0x0  nop
    ctx->pc = 0x125114u;
    // NOP
label_125118:
    // 0x125118: 0x54400018  bnel        $v0, $zero, . + 4 + (0x18 << 2)
    ctx->pc = 0x125118u;
    {
        const bool branch_taken_0x125118 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125118) {
            ctx->pc = 0x12511Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125118u;
            // 0x12511c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12517Cu;
            goto label_12517c;
        }
    }
    ctx->pc = 0x125120u;
    // 0x125120: 0x8d62009c  lw          $v0, 0x9C($t3)
    ctx->pc = 0x125120u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 156)));
    // 0x125124: 0x5440000e  bnel        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x125124u;
    {
        const bool branch_taken_0x125124 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125124) {
            ctx->pc = 0x125128u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125124u;
            // 0x125128: 0x9562009c  lhu         $v0, 0x9C($t3) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 156)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125160u;
            goto label_125160;
        }
    }
    ctx->pc = 0x12512Cu;
    // 0x12512c: 0x856200a0  lh          $v0, 0xA0($t3)
    ctx->pc = 0x12512cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 11), 160)));
    // 0x125130: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x125130u;
    {
        const bool branch_taken_0x125130 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125130) {
            ctx->pc = 0x125134u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125130u;
            // 0x125134: 0x9562009c  lhu         $v0, 0x9C($t3) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 156)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125160u;
            goto label_125160;
        }
    }
    ctx->pc = 0x125138u;
    // 0x125138: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x125138u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12513c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12513cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x125140: 0x9443b94c  lhu         $v1, -0x46B4($v0)
    ctx->pc = 0x125140u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294949196)));
    // 0x125144: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x125144u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x125148: 0xa563009c  sh          $v1, 0x9C($t3)
    ctx->pc = 0x125148u;
    WRITE16(ADD32(GPR_U32(ctx, 11), 156), (uint16_t)GPR_U32(ctx, 3));
    // 0x12514c: 0x9482b94e  lhu         $v0, -0x46B2($a0)
    ctx->pc = 0x12514cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 4294949198)));
    // 0x125150: 0xa562009e  sh          $v0, 0x9E($t3)
    ctx->pc = 0x125150u;
    WRITE16(ADD32(GPR_U32(ctx, 11), 158), (uint16_t)GPR_U32(ctx, 2));
    // 0x125154: 0x94a3b950  lhu         $v1, -0x46B0($a1)
    ctx->pc = 0x125154u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 4294949200)));
    // 0x125158: 0xa56300a0  sh          $v1, 0xA0($t3)
    ctx->pc = 0x125158u;
    WRITE16(ADD32(GPR_U32(ctx, 11), 160), (uint16_t)GPR_U32(ctx, 3));
    // 0x12515c: 0x9562009c  lhu         $v0, 0x9C($t3)
    ctx->pc = 0x12515cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 156)));
label_125160:
    // 0x125160: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x125160u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x125164: 0x9563009e  lhu         $v1, 0x9E($t3)
    ctx->pc = 0x125164u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 158)));
    // 0x125168: 0xa6230000  sh          $v1, 0x0($s1)
    ctx->pc = 0x125168u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x12516c: 0x956200a0  lhu         $v0, 0xA0($t3)
    ctx->pc = 0x12516cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 11), 160)));
    // 0x125170: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x125170u;
    {
        const bool branch_taken_0x125170 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125170u;
            // 0x125174: 0xa6420000  sh          $v0, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125170) {
            ctx->pc = 0x125184u;
            goto label_125184;
        }
    }
    ctx->pc = 0x125178u;
label_125178:
    // 0x125178: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x125178u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_12517c:
    // 0x12517c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x12517cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x125180: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x125180u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
label_125184:
    // 0x125184: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x125184u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_125188:
    // 0x125188: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x125188u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12518c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12518cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x125190: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x125190u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125194: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x125194u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x125198: 0x3e00008  jr          $ra
    ctx->pc = 0x125198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12519Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125198u;
            // 0x12519c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1250F4u: goto label_1250f4;
            case 0x12510Cu: goto label_12510c;
            case 0x125118u: goto label_125118;
            case 0x125160u: goto label_125160;
            case 0x125178u: goto label_125178;
            case 0x12517Cu: goto label_12517c;
            case 0x125184u: goto label_125184;
            case 0x125188u: goto label_125188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1251A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
