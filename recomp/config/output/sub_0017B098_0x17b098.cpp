#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B098
// Address: 0x17b098 - 0x17b288
void sub_0017B098_0x17b098(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B098_0x17b098");
#endif

    switch (ctx->pc) {
        case 0x17b138u: goto label_17b138;
        case 0x17b174u: goto label_17b174;
        case 0x17b1a8u: goto label_17b1a8;
        case 0x17b1d8u: goto label_17b1d8;
        case 0x17b208u: goto label_17b208;
        case 0x17b238u: goto label_17b238;
        default: break;
    }

    ctx->pc = 0x17b098u;

    // 0x17b098: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17b098u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17b09c: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17b09cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17b0a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17b0a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17b0a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17b0a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b0a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17b0a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17b0ac: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17b0acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b0b0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17b0b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17b0b4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17b0b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17b0b8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x17b0b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17b0bc: 0x10620050  beq         $v1, $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x17B0BCu;
    {
        const bool branch_taken_0x17b0bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B0C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0BCu;
            // 0x17b0c0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0bc) {
            ctx->pc = 0x17B200u;
            goto label_17b200;
        }
    }
    ctx->pc = 0x17B0C4u;
    // 0x17b0c4: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17b0c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17b0c8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x17B0C8u;
    {
        const bool branch_taken_0x17b0c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B0CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0C8u;
            // 0x17b0cc: 0x24020101  addiu       $v0, $zero, 0x101 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0c8) {
            ctx->pc = 0x17B108u;
            goto label_17b108;
        }
    }
    ctx->pc = 0x17B0D0u;
    // 0x17b0d0: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17b0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17b0d4: 0x10620056  beq         $v1, $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x17B0D4u;
    {
        const bool branch_taken_0x17b0d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0D4u;
            // 0x17b0d8: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0d4) {
            ctx->pc = 0x17B230u;
            goto label_17b230;
        }
    }
    ctx->pc = 0x17B0DCu;
    // 0x17b0dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17B0DCu;
    {
        const bool branch_taken_0x17b0dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B0E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0DCu;
            // 0x17b0e0: 0x24020031  addiu       $v0, $zero, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0dc) {
            ctx->pc = 0x17B0F8u;
            goto label_17b0f8;
        }
    }
    ctx->pc = 0x17B0E4u;
    // 0x17b0e4: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17b0e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17b0e8: 0x10620011  beq         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x17B0E8u;
    {
        const bool branch_taken_0x17b0e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b0e8) {
            ctx->pc = 0x17B130u;
            goto label_17b130;
        }
    }
    ctx->pc = 0x17B0F0u;
    // 0x17b0f0: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x17B0F0u;
    {
        const bool branch_taken_0x17b0f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B0F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0F0u;
            // 0x17b0f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0f0) {
            ctx->pc = 0x17B264u;
            goto label_17b264;
        }
    }
    ctx->pc = 0x17B0F8u;
label_17b0f8:
    // 0x17b0f8: 0x10620035  beq         $v1, $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x17B0F8u;
    {
        const bool branch_taken_0x17b0f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b0f8) {
            ctx->pc = 0x17B1D0u;
            goto label_17b1d0;
        }
    }
    ctx->pc = 0x17B100u;
    // 0x17b100: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x17B100u;
    {
        const bool branch_taken_0x17b100 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B100u;
            // 0x17b104: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b100) {
            ctx->pc = 0x17B264u;
            goto label_17b264;
        }
    }
    ctx->pc = 0x17B108u;
label_17b108:
    // 0x17b108: 0x10620055  beq         $v1, $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x17B108u;
    {
        const bool branch_taken_0x17b108 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B108u;
            // 0x17b10c: 0x28620102  slti        $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)258) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b108) {
            ctx->pc = 0x17B260u;
            goto label_17b260;
        }
    }
    ctx->pc = 0x17B110u;
    // 0x17b110: 0x54400054  bnel        $v0, $zero, . + 4 + (0x54 << 2)
    ctx->pc = 0x17B110u;
    {
        const bool branch_taken_0x17b110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17b110) {
            ctx->pc = 0x17B114u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17B110u;
            // 0x17b114: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17B264u;
            goto label_17b264;
        }
    }
    ctx->pc = 0x17B118u;
    // 0x17b118: 0x24021001  addiu       $v0, $zero, 0x1001
    ctx->pc = 0x17b118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4097));
    // 0x17b11c: 0x10620020  beq         $v1, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x17B11Cu;
    {
        const bool branch_taken_0x17b11c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b11c) {
            ctx->pc = 0x17B1A0u;
            goto label_17b1a0;
        }
    }
    ctx->pc = 0x17B124u;
    // 0x17b124: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x17B124u;
    {
        const bool branch_taken_0x17b124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B124u;
            // 0x17b128: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b124) {
            ctx->pc = 0x17B264u;
            goto label_17b264;
        }
    }
    ctx->pc = 0x17B12Cu;
    // 0x17b12c: 0x0  nop
    ctx->pc = 0x17b12cu;
    // NOP
label_17b130:
    // 0x17b130: 0xc05f51a  jal         func_17D468
    ctx->pc = 0x17B130u;
    SET_GPR_U32(ctx, 31, 0x17B138u);
    ctx->pc = 0x17D468u;
    if (runtime->hasFunction(0x17D468u)) {
        auto targetFn = runtime->lookupFunction(0x17D468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B138u; }
        if (ctx->pc != 0x17B138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D468_0x17d468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B138u; }
        if (ctx->pc != 0x17B138u) { return; }
    }
    ctx->pc = 0x17B138u;
label_17b138:
    // 0x17b138: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17b138u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b13c: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17B13Cu;
    {
        const bool branch_taken_0x17b13c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17B140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B13Cu;
            // 0x17b140: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b13c) {
            ctx->pc = 0x17B168u;
            goto label_17b168;
        }
    }
    ctx->pc = 0x17B144u;
    // 0x17b144: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b144u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b148: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b148u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b14c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b14cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b150: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b150u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b154: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b154u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b158: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b158u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b15c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17b15cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b160: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B160u;
    ctx->pc = 0x17B164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B160u;
            // 0x17b164: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    if (runtime->hasFunction(0x17B288u)) {
        auto targetFn = runtime->lookupFunction(0x17B288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B288_0x17b288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B168u;
label_17b168:
    // 0x17b168: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b168u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b16c: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B16Cu;
    SET_GPR_U32(ctx, 31, 0x17B174u);
    ctx->pc = 0x17B170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B16Cu;
            // 0x17b170: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B174u; }
        if (ctx->pc != 0x17B174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B174u; }
        if (ctx->pc != 0x17B174u) { return; }
    }
    ctx->pc = 0x17B174u;
label_17b174:
    // 0x17b174: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b174u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b178: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b178u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b17c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b17cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b180: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b180u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b184: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b184u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b188: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b188u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b18c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b18cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b190: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b190u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b194: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B194u;
    ctx->pc = 0x17B198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B194u;
            // 0x17b198: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    if (runtime->hasFunction(0x17B288u)) {
        auto targetFn = runtime->lookupFunction(0x17B288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B288_0x17b288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B19Cu;
    // 0x17b19c: 0x0  nop
    ctx->pc = 0x17b19cu;
    // NOP
label_17b1a0:
    // 0x17b1a0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B1A0u;
    SET_GPR_U32(ctx, 31, 0x17B1A8u);
    ctx->pc = 0x17B1A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B1A0u;
            // 0x17b1a4: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B1A8u; }
        if (ctx->pc != 0x17B1A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B1A8u; }
        if (ctx->pc != 0x17B1A8u) { return; }
    }
    ctx->pc = 0x17B1A8u;
label_17b1a8:
    // 0x17b1a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b1a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1ac: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b1acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b1b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b1b4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b1b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1b8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b1b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b1bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b1bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b1c0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b1c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b1c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b1c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b1c8: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B1C8u;
    ctx->pc = 0x17B1CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B1C8u;
            // 0x17b1cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    if (runtime->hasFunction(0x17B288u)) {
        auto targetFn = runtime->lookupFunction(0x17B288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B288_0x17b288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B1D0u;
label_17b1d0:
    // 0x17b1d0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B1D0u;
    SET_GPR_U32(ctx, 31, 0x17B1D8u);
    ctx->pc = 0x17B1D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B1D0u;
            // 0x17b1d4: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B1D8u; }
        if (ctx->pc != 0x17B1D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B1D8u; }
        if (ctx->pc != 0x17B1D8u) { return; }
    }
    ctx->pc = 0x17B1D8u;
label_17b1d8:
    // 0x17b1d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b1d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1dc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b1dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b1e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b1e4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b1e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1e8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b1e8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b1ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b1ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b1f0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b1f0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b1f4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b1f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b1f8: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B1F8u;
    ctx->pc = 0x17B1FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B1F8u;
            // 0x17b1fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    if (runtime->hasFunction(0x17B288u)) {
        auto targetFn = runtime->lookupFunction(0x17B288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B288_0x17b288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B200u;
label_17b200:
    // 0x17b200: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B200u;
    SET_GPR_U32(ctx, 31, 0x17B208u);
    ctx->pc = 0x17B204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B200u;
            // 0x17b204: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B208u; }
        if (ctx->pc != 0x17B208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B208u; }
        if (ctx->pc != 0x17B208u) { return; }
    }
    ctx->pc = 0x17B208u;
label_17b208:
    // 0x17b208: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b208u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b20c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b20cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b210: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b210u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b214: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b214u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b218: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b218u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b21c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b21cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b220: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b220u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b224: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b224u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b228: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B228u;
    ctx->pc = 0x17B22Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B228u;
            // 0x17b22c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    if (runtime->hasFunction(0x17B288u)) {
        auto targetFn = runtime->lookupFunction(0x17B288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B288_0x17b288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B230u;
label_17b230:
    // 0x17b230: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B230u;
    SET_GPR_U32(ctx, 31, 0x17B238u);
    ctx->pc = 0x17B234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B230u;
            // 0x17b234: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B238u; }
        if (ctx->pc != 0x17B238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B238u; }
        if (ctx->pc != 0x17B238u) { return; }
    }
    ctx->pc = 0x17B238u;
label_17b238:
    // 0x17b238: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b238u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b23c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b23cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b240: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b240u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b244: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b244u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b248: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b248u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b24c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b24cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b250: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b250u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b254: 0x805ecd8  j           func_17B360
    ctx->pc = 0x17B254u;
    ctx->pc = 0x17B258u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B254u;
            // 0x17b258: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B360u;
    if (runtime->hasFunction(0x17B360u)) {
        auto targetFn = runtime->lookupFunction(0x17B360u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B360_0x17b360(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B25Cu;
    // 0x17b25c: 0x0  nop
    ctx->pc = 0x17b25cu;
    // NOP
label_17b260:
    // 0x17b260: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b260u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_17b264:
    // 0x17b264: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b264u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b268: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b268u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b26c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b26cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b270: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17b270u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17b274: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b274u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b278: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b278u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b27c: 0x24c60e70  addiu       $a2, $a2, 0xE70
    ctx->pc = 0x17b27cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 3696));
    // 0x17b280: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17B280u;
    ctx->pc = 0x17B284u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B280u;
            // 0x17b284: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B288u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
