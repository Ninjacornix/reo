#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00156400
// Address: 0x156400 - 0x156548
void sub_00156400_0x156400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00156400_0x156400");
#endif

    switch (ctx->pc) {
        case 0x15643cu: goto label_15643c;
        case 0x156450u: goto label_156450;
        case 0x156458u: goto label_156458;
        case 0x15647cu: goto label_15647c;
        default: break;
    }

    ctx->pc = 0x156400u;

    // 0x156400: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x156400u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x156404: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x156404u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x156408: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x156408u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15640c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x15640cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x156410: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x156410u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156414: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x156414u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x156418: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x156418u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15641c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15641cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x156420: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x156420u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156424: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x156424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x156428: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x156428u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15642c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x15642cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x156430: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x156430u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x156434: 0xc0560f2  jal         func_1583C8
    ctx->pc = 0x156434u;
    SET_GPR_U32(ctx, 31, 0x15643Cu);
    ctx->pc = 0x156438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x156434u;
            // 0x156438: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1583C8u;
    if (runtime->hasFunction(0x1583C8u)) {
        auto targetFn = runtime->lookupFunction(0x1583C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15643Cu; }
        if (ctx->pc != 0x15643Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583C8_0x1583c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15643Cu; }
        if (ctx->pc != 0x15643Cu) { return; }
    }
    ctx->pc = 0x15643Cu;
label_15643c:
    // 0x15643c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15643Cu;
    {
        const bool branch_taken_0x15643c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x156440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15643Cu;
            // 0x156440: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15643c) {
            ctx->pc = 0x156458u;
            goto label_156458;
        }
    }
    ctx->pc = 0x156444u;
    // 0x156444: 0x3c05ff02  lui         $a1, 0xFF02
    ctx->pc = 0x156444u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65282 << 16));
    // 0x156448: 0xc05607e  jal         func_1581F8
    ctx->pc = 0x156448u;
    SET_GPR_U32(ctx, 31, 0x156450u);
    ctx->pc = 0x15644Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x156448u;
            // 0x15644c: 0x34a50301  ori         $a1, $a1, 0x301 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)769);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581F8u;
    if (runtime->hasFunction(0x1581F8u)) {
        auto targetFn = runtime->lookupFunction(0x1581F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x156450u; }
        if (ctx->pc != 0x156450u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001581F8_0x1581f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x156450u; }
        if (ctx->pc != 0x156450u) { return; }
    }
    ctx->pc = 0x156450u;
label_156450:
    // 0x156450: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x156450u;
    {
        const bool branch_taken_0x156450 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156450u;
            // 0x156454: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156450) {
            ctx->pc = 0x15652Cu;
            goto label_15652c;
        }
    }
    ctx->pc = 0x156458u;
label_156458:
    // 0x156458: 0x2a020004  slti        $v0, $s0, 0x4
    ctx->pc = 0x156458u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x15645c: 0x54400013  bnel        $v0, $zero, . + 4 + (0x13 << 2)
    ctx->pc = 0x15645Cu;
    {
        const bool branch_taken_0x15645c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15645c) {
            ctx->pc = 0x156460u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15645Cu;
            // 0x156460: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1564ACu;
            goto label_1564ac;
        }
    }
    ctx->pc = 0x156464u;
    // 0x156464: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x156464u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156468: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x156468u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15646c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x15646cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156470: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x156470u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156474: 0xc055952  jal         func_156548
    ctx->pc = 0x156474u;
    SET_GPR_U32(ctx, 31, 0x15647Cu);
    ctx->pc = 0x156478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x156474u;
            // 0x156478: 0x27a80004  addiu       $t0, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x156548u;
    if (runtime->hasFunction(0x156548u)) {
        auto targetFn = runtime->lookupFunction(0x156548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15647Cu; }
        if (ctx->pc != 0x15647Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00156548_0x156548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15647Cu; }
        if (ctx->pc != 0x15647Cu) { return; }
    }
    ctx->pc = 0x15647Cu;
label_15647c:
    // 0x15647c: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x15647cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x156480: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x156480u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x156484: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x156484u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x156488: 0x8e640000  lw          $a0, 0x0($s3)
    ctx->pc = 0x156488u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x15648c: 0x2238821  addu        $s1, $s1, $v1
    ctx->pc = 0x15648cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x156490: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x156490u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x156494: 0x2038023  subu        $s0, $s0, $v1
    ctx->pc = 0x156494u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x156498: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x156498u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x15649c: 0xae450000  sw          $a1, 0x0($s2)
    ctx->pc = 0x15649cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 5));
    // 0x1564a0: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1564A0u;
    {
        const bool branch_taken_0x1564a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1564A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1564A0u;
            // 0x1564a4: 0xae640000  sw          $a0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1564a0) {
            ctx->pc = 0x156458u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_156458;
        }
    }
    ctx->pc = 0x1564A8u;
    // 0x1564a8: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x1564a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_1564ac:
    // 0x1564ac: 0x3c030002  lui         $v1, 0x2
    ctx->pc = 0x1564acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)2 << 16));
    // 0x1564b0: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1564b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1564b4: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1564B4u;
    {
        const bool branch_taken_0x1564b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1564B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1564B4u;
            // 0x1564b8: 0x26850020  addiu       $a1, $s4, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1564b4) {
            ctx->pc = 0x156524u;
            goto label_156524;
        }
    }
    ctx->pc = 0x1564BCu;
    // 0x1564bc: 0x8ca20008  lw          $v0, 0x8($a1)
    ctx->pc = 0x1564bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1564c0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1564C0u;
    {
        const bool branch_taken_0x1564c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1564C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1564C0u;
            // 0x1564c4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1564c0) {
            ctx->pc = 0x1564D8u;
            goto label_1564d8;
        }
    }
    ctx->pc = 0x1564C8u;
    // 0x1564c8: 0x8ca3000c  lw          $v1, 0xC($a1)
    ctx->pc = 0x1564c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x1564cc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1564ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1564d0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1564d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1564d4: 0x43200a  movz        $a0, $v0, $v1
    ctx->pc = 0x1564d4u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 2));
label_1564d8:
    // 0x1564d8: 0x41140  sll         $v0, $a0, 5
    ctx->pc = 0x1564d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x1564dc: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x1564dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x1564e0: 0x2821021  addu        $v0, $s4, $v0
    ctx->pc = 0x1564e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x1564e4: 0x68a30007  ldl         $v1, 0x7($a1)
    ctx->pc = 0x1564e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1564e8: 0x6ca30000  ldr         $v1, 0x0($a1)
    ctx->pc = 0x1564e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1564ec: 0x68a4000f  ldl         $a0, 0xF($a1)
    ctx->pc = 0x1564ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1564f0: 0x6ca40008  ldr         $a0, 0x8($a1)
    ctx->pc = 0x1564f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1564f4: 0x68a60017  ldl         $a2, 0x17($a1)
    ctx->pc = 0x1564f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1564f8: 0x6ca60010  ldr         $a2, 0x10($a1)
    ctx->pc = 0x1564f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1564fc: 0x68a7001f  ldl         $a3, 0x1F($a1)
    ctx->pc = 0x1564fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x156500: 0x6ca70018  ldr         $a3, 0x18($a1)
    ctx->pc = 0x156500u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x156504: 0xb0430007  sdl         $v1, 0x7($v0)
    ctx->pc = 0x156504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x156508: 0xb4430000  sdr         $v1, 0x0($v0)
    ctx->pc = 0x156508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15650c: 0xb044000f  sdl         $a0, 0xF($v0)
    ctx->pc = 0x15650cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x156510: 0xb4440008  sdr         $a0, 0x8($v0)
    ctx->pc = 0x156510u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x156514: 0xb0460017  sdl         $a2, 0x17($v0)
    ctx->pc = 0x156514u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x156518: 0xb4460010  sdr         $a2, 0x10($v0)
    ctx->pc = 0x156518u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15651c: 0xb047001f  sdl         $a3, 0x1F($v0)
    ctx->pc = 0x15651cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x156520: 0xb4470018  sdr         $a3, 0x18($v0)
    ctx->pc = 0x156520u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
label_156524:
    // 0x156524: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x156524u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156528: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x156528u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_15652c:
    // 0x15652c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15652cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x156530: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x156530u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x156534: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x156534u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x156538: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x156538u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15653c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x15653cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x156540: 0x3e00008  jr          $ra
    ctx->pc = 0x156540u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x156544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156540u;
            // 0x156544: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15643Cu: goto label_15643c;
            case 0x156450u: goto label_156450;
            case 0x156458u: goto label_156458;
            case 0x15647Cu: goto label_15647c;
            case 0x1564ACu: goto label_1564ac;
            case 0x1564D8u: goto label_1564d8;
            case 0x156524u: goto label_156524;
            case 0x15652Cu: goto label_15652c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x156548u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
