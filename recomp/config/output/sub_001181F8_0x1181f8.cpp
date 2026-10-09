#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001181F8
// Address: 0x1181f8 - 0x118620
void sub_001181F8_0x1181f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001181F8_0x1181f8");
#endif

    switch (ctx->pc) {
        case 0x118214u: goto label_118214;
        case 0x11821cu: goto label_11821c;
        case 0x118230u: goto label_118230;
        case 0x11824cu: goto label_11824c;
        case 0x118304u: goto label_118304;
        case 0x118358u: goto label_118358;
        case 0x1183a8u: goto label_1183a8;
        case 0x118410u: goto label_118410;
        case 0x11846cu: goto label_11846c;
        case 0x118598u: goto label_118598;
        case 0x1185d4u: goto label_1185d4;
        case 0x11860cu: goto label_11860c;
        default: break;
    }

    ctx->pc = 0x1181f8u;

    // 0x1181f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1181f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1181fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1181fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x118200: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x118200u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x118204: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x118204u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118208: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x118208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11820c: 0xc046044  jal         func_118110
    ctx->pc = 0x11820Cu;
    SET_GPR_U32(ctx, 31, 0x118214u);
    ctx->pc = 0x118210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11820Cu;
            // 0x118210: 0x3c110021  lui         $s1, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118110u;
    if (runtime->hasFunction(0x118110u)) {
        auto targetFn = runtime->lookupFunction(0x118110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118214u; }
        if (ctx->pc != 0x118214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118110_0x118110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118214u; }
        if (ctx->pc != 0x118214u) { return; }
    }
    ctx->pc = 0x118214u;
label_118214:
    // 0x118214: 0xc045198  jal         func_114660
    ctx->pc = 0x118214u;
    SET_GPR_U32(ctx, 31, 0x11821Cu);
    ctx->pc = 0x118218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118214u;
            // 0x118218: 0x8e249de8  lw          $a0, -0x6218($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11821Cu; }
        if (ctx->pc != 0x11821Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11821Cu; }
        if (ctx->pc != 0x11821Cu) { return; }
    }
    ctx->pc = 0x11821Cu;
label_11821c:
    // 0x11821c: 0x2e030020  sltiu       $v1, $s0, 0x20
    ctx->pc = 0x11821cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x118220: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x118220u;
    {
        const bool branch_taken_0x118220 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x118224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118220u;
            // 0x118224: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118220) {
            ctx->pc = 0x118238u;
            goto label_118238;
        }
    }
    ctx->pc = 0x118228u;
    // 0x118228: 0xc045190  jal         func_114640
    ctx->pc = 0x118228u;
    SET_GPR_U32(ctx, 31, 0x118230u);
    ctx->pc = 0x11822Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118228u;
            // 0x11822c: 0x8e249de8  lw          $a0, -0x6218($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118230u; }
        if (ctx->pc != 0x118230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118230u; }
        if (ctx->pc != 0x118230u) { return; }
    }
    ctx->pc = 0x118230u;
label_118230:
    // 0x118230: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x118230u;
    {
        const bool branch_taken_0x118230 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118230u;
            // 0x118234: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118230) {
            ctx->pc = 0x118250u;
            goto label_118250;
        }
    }
    ctx->pc = 0x118238u;
label_118238:
    // 0x118238: 0x108100  sll         $s0, $s0, 4
    ctx->pc = 0x118238u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x11823c: 0x2442df40  addiu       $v0, $v0, -0x20C0
    ctx->pc = 0x11823cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958912));
    // 0x118240: 0x8e249de8  lw          $a0, -0x6218($s1)
    ctx->pc = 0x118240u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
    // 0x118244: 0xc045190  jal         func_114640
    ctx->pc = 0x118244u;
    SET_GPR_U32(ctx, 31, 0x11824Cu);
    ctx->pc = 0x118248u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118244u;
            // 0x118248: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11824Cu; }
        if (ctx->pc != 0x11824Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11824Cu; }
        if (ctx->pc != 0x11824Cu) { return; }
    }
    ctx->pc = 0x11824Cu;
label_11824c:
    // 0x11824c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11824cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_118250:
    // 0x118250: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x118250u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x118254: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x118254u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x118258: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x118258u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11825c: 0x3e00008  jr          $ra
    ctx->pc = 0x11825Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11825Cu;
            // 0x118260: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118214u: goto label_118214;
            case 0x11821Cu: goto label_11821c;
            case 0x118230u: goto label_118230;
            case 0x118238u: goto label_118238;
            case 0x11824Cu: goto label_11824c;
            case 0x118250u: goto label_118250;
            case 0x118288u: goto label_118288;
            case 0x118304u: goto label_118304;
            case 0x118330u: goto label_118330;
            case 0x118358u: goto label_118358;
            case 0x118380u: goto label_118380;
            case 0x1183A8u: goto label_1183a8;
            case 0x1183D8u: goto label_1183d8;
            case 0x118410u: goto label_118410;
            case 0x11846Cu: goto label_11846c;
            case 0x1184A0u: goto label_1184a0;
            case 0x1184B4u: goto label_1184b4;
            case 0x118550u: goto label_118550;
            case 0x118590u: goto label_118590;
            case 0x118598u: goto label_118598;
            case 0x11859Cu: goto label_11859c;
            case 0x1185D0u: goto label_1185d0;
            case 0x1185D4u: goto label_1185d4;
            case 0x118604u: goto label_118604;
            case 0x11860Cu: goto label_11860c;
            case 0x118610u: goto label_118610;
            default: break;
        }
        return;
    }
    ctx->pc = 0x118264u;
    // 0x118264: 0x0  nop
    ctx->pc = 0x118264u;
    // NOP
    // 0x118268: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x118268u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11826c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11826cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x118270: 0x8c439de0  lw          $v1, -0x6220($v0)
    ctx->pc = 0x118270u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942176)));
    // 0x118274: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x118274u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118278: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x118278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11827c: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x11827Cu;
    {
        const bool branch_taken_0x11827c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x118280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11827Cu;
            // 0x118280: 0xffb00020  sd          $s0, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11827c) {
            ctx->pc = 0x118288u;
            goto label_118288;
        }
    }
    ctx->pc = 0x118284u;
    // 0x118284: 0x8c85000c  lw          $a1, 0xC($a0)
    ctx->pc = 0x118284u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
label_118288:
    // 0x118288: 0x24030440  addiu       $v1, $zero, 0x440
    ctx->pc = 0x118288u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1088));
    // 0x11828c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11828cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x118290: 0xa31818  mult        $v1, $a1, $v1
    ctx->pc = 0x118290u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x118294: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x118294u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x118298: 0xac459dd8  sw          $a1, -0x6228($v0)
    ctx->pc = 0x118298u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294942168), GPR_U32(ctx, 5));
    // 0x11829c: 0x2484d6c0  addiu       $a0, $a0, -0x2940
    ctx->pc = 0x11829cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956736));
    // 0x1182a0: 0x3c052000  lui         $a1, 0x2000
    ctx->pc = 0x1182a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)8192 << 16));
    // 0x1182a4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1182a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1182a8: 0x658025  or          $s0, $v1, $a1
    ctx->pc = 0x1182a8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x1182ac: 0x8a020003  lwl         $v0, 0x3($s0)
    ctx->pc = 0x1182acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x1182b0: 0x9a020000  lwr         $v0, 0x0($s0)
    ctx->pc = 0x1182b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x1182b4: 0xaba20003  swl         $v0, 0x3($sp)
    ctx->pc = 0x1182b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1182b8: 0xbba20000  swr         $v0, 0x0($sp)
    ctx->pc = 0x1182b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1182bc: 0x8a060007  lwl         $a2, 0x7($s0)
    ctx->pc = 0x1182bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 6) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 6, (int32_t)merged); }
    // 0x1182c0: 0x9a060004  lwr         $a2, 0x4($s0)
    ctx->pc = 0x1182c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 6) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 6) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 6, merged64); }
    // 0x1182c4: 0xaba60007  swl         $a2, 0x7($sp)
    ctx->pc = 0x1182c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 6); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1182c8: 0xbba60004  swr         $a2, 0x4($sp)
    ctx->pc = 0x1182c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 6); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1182cc: 0x8a03000b  lwl         $v1, 0xB($s0)
    ctx->pc = 0x1182ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x1182d0: 0x9a030008  lwr         $v1, 0x8($s0)
    ctx->pc = 0x1182d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x1182d4: 0xaba3000b  swl         $v1, 0xB($sp)
    ctx->pc = 0x1182d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1182d8: 0xbba30008  swr         $v1, 0x8($sp)
    ctx->pc = 0x1182d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1182dc: 0x8a07000f  lwl         $a3, 0xF($s0)
    ctx->pc = 0x1182dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 7) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 7, (int32_t)merged); }
    // 0x1182e0: 0x9a07000c  lwr         $a3, 0xC($s0)
    ctx->pc = 0x1182e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 7) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 7) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 7, merged64); }
    // 0x1182e4: 0xaba7000f  swl         $a3, 0xF($sp)
    ctx->pc = 0x1182e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1182e8: 0xbba7000c  swr         $a3, 0xC($sp)
    ctx->pc = 0x1182e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 12); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1182ec: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1182ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1182f0: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1182F0u;
    {
        const bool branch_taken_0x1182f0 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1182F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1182F0u;
            // 0x1182f4: 0x8fa40008  lw          $a0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1182f0) {
            ctx->pc = 0x118304u;
            goto label_118304;
        }
    }
    ctx->pc = 0x1182F8u;
    // 0x1182f8: 0x26050010  addiu       $a1, $s0, 0x10
    ctx->pc = 0x1182f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x1182fc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1182FCu;
    SET_GPR_U32(ctx, 31, 0x118304u);
    ctx->pc = 0x118300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1182FCu;
            // 0x118300: 0x8fa6000c  lw          $a2, 0xC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118304u; }
        if (ctx->pc != 0x118304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118304u; }
        if (ctx->pc != 0x118304u) { return; }
    }
    ctx->pc = 0x118304u;
label_118304:
    // 0x118304: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x118304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x118308: 0x2444fffe  addiu       $a0, $v0, -0x2
    ctx->pc = 0x118308u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967294));
    // 0x11830c: 0x2c830019  sltiu       $v1, $a0, 0x19
    ctx->pc = 0x11830cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)25) ? 1 : 0);
    // 0x118310: 0x106000a1  beqz        $v1, . + 4 + (0xA1 << 2)
    ctx->pc = 0x118310u;
    {
        const bool branch_taken_0x118310 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x118314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118310u;
            // 0x118314: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118310) {
            ctx->pc = 0x118598u;
            goto label_118598;
        }
    }
    ctx->pc = 0x118318u;
    // 0x118318: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x118318u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x11831c: 0x24428b20  addiu       $v0, $v0, -0x74E0
    ctx->pc = 0x11831cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937376));
    // 0x118320: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x118320u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x118324: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x118324u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x118328: 0x800008  jr          $a0
    ctx->pc = 0x118328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118330u: goto label_118330;
            case 0x1183D8u: goto label_1183d8;
            case 0x1184B4u: goto label_1184b4;
            case 0x118550u: goto label_118550;
            case 0x118598u: goto label_118598;
            default: break;
        }
        return;
    }
    ctx->pc = 0x118330u;
label_118330:
    // 0x118330: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x118330u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x118334: 0x18600012  blez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x118334u;
    {
        const bool branch_taken_0x118334 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x118338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118334u;
            // 0x118338: 0x26070014  addiu       $a3, $s0, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118334) {
            ctx->pc = 0x118380u;
            goto label_118380;
        }
    }
    ctx->pc = 0x11833Cu;
    // 0x11833c: 0x8ce80008  lw          $t0, 0x8($a3)
    ctx->pc = 0x11833cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x118340: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x118340u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x118344: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x118344u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118348: 0x1860000d  blez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x118348u;
    {
        const bool branch_taken_0x118348 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x11834Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118348u;
            // 0x11834c: 0x1025025  or          $t2, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118348) {
            ctx->pc = 0x118380u;
            goto label_118380;
        }
    }
    ctx->pc = 0x118350u;
    // 0x118350: 0x26090024  addiu       $t1, $s0, 0x24
    ctx->pc = 0x118350u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x118354: 0x1261021  addu        $v0, $t1, $a2
    ctx->pc = 0x118354u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
label_118358:
    // 0x118358: 0x1462821  addu        $a1, $t2, $a2
    ctx->pc = 0x118358u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
    // 0x11835c: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11835cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x118360: 0x1062021  addu        $a0, $t0, $a2
    ctx->pc = 0x118360u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
    // 0x118364: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x118364u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x118368: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x118368u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11836c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11836cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x118370: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x118370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x118374: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x118374u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x118378: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x118378u;
    {
        const bool branch_taken_0x118378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11837Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118378u;
            // 0x11837c: 0x1261021  addu        $v0, $t1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118378) {
            ctx->pc = 0x118358u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_118358;
        }
    }
    ctx->pc = 0x118380u;
label_118380:
    // 0x118380: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x118380u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x118384: 0x18600084  blez        $v1, . + 4 + (0x84 << 2)
    ctx->pc = 0x118384u;
    {
        const bool branch_taken_0x118384 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x118388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118384u;
            // 0x118388: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118384) {
            ctx->pc = 0x118598u;
            goto label_118598;
        }
    }
    ctx->pc = 0x11838Cu;
    // 0x11838c: 0x8ce8000c  lw          $t0, 0xC($a3)
    ctx->pc = 0x11838cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x118390: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x118390u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118394: 0x18600080  blez        $v1, . + 4 + (0x80 << 2)
    ctx->pc = 0x118394u;
    {
        const bool branch_taken_0x118394 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x118398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118394u;
            // 0x118398: 0x1025025  or          $t2, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 10, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118394) {
            ctx->pc = 0x118598u;
            goto label_118598;
        }
    }
    ctx->pc = 0x11839Cu;
    // 0x11839c: 0x24e90050  addiu       $t1, $a3, 0x50
    ctx->pc = 0x11839cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), 80));
    // 0x1183a0: 0x1261021  addu        $v0, $t1, $a2
    ctx->pc = 0x1183a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x1183a4: 0x0  nop
    ctx->pc = 0x1183a4u;
    // NOP
label_1183a8:
    // 0x1183a8: 0x1462821  addu        $a1, $t2, $a2
    ctx->pc = 0x1183a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 6)));
    // 0x1183ac: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1183acu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1183b0: 0x1062021  addu        $a0, $t0, $a2
    ctx->pc = 0x1183b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
    // 0x1183b4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1183b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1183b8: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x1183b8u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1183bc: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1183bcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1183c0: 0x8ce20004  lw          $v0, 0x4($a3)
    ctx->pc = 0x1183c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1183c4: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x1183c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1183c8: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1183C8u;
    {
        const bool branch_taken_0x1183c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1183CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1183C8u;
            // 0x1183cc: 0x1261021  addu        $v0, $t1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1183c8) {
            ctx->pc = 0x1183A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1183a8;
        }
    }
    ctx->pc = 0x1183D0u;
    // 0x1183d0: 0x10000072  b           . + 4 + (0x72 << 2)
    ctx->pc = 0x1183D0u;
    {
        const bool branch_taken_0x1183d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1183D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1183D0u;
            // 0x1183d4: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1183d0) {
            ctx->pc = 0x11859Cu;
            goto label_11859c;
        }
    }
    ctx->pc = 0x1183D8u;
label_1183d8:
    // 0x1183d8: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x1183d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1183dc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1183dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1183e0: 0x1860006e  blez        $v1, . + 4 + (0x6E << 2)
    ctx->pc = 0x1183E0u;
    {
        const bool branch_taken_0x1183e0 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x1183E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1183E0u;
            // 0x1183e4: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1183e0) {
            ctx->pc = 0x11859Cu;
            goto label_11859c;
        }
    }
    ctx->pc = 0x1183E8u;
    // 0x1183e8: 0x8a040017  lwl         $a0, 0x17($s0)
    ctx->pc = 0x1183e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x1183ec: 0x9a040014  lwr         $a0, 0x14($s0)
    ctx->pc = 0x1183ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x1183f0: 0xaba40013  swl         $a0, 0x13($sp)
    ctx->pc = 0x1183f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1183f4: 0xbba40010  swr         $a0, 0x10($sp)
    ctx->pc = 0x1183f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1183f8: 0x26040018  addiu       $a0, $s0, 0x18
    ctx->pc = 0x1183f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x1183fc: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x1183fcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x118400: 0x861025  or          $v0, $a0, $a2
    ctx->pc = 0x118400u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x118404: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x118404u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x118408: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x118408u;
    {
        const bool branch_taken_0x118408 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11840Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118408u;
            // 0x11840c: 0x26020158  addiu       $v0, $s0, 0x158 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118408) {
            ctx->pc = 0x11846Cu;
            goto label_11846c;
        }
    }
    ctx->pc = 0x118410u;
label_118410:
    // 0x118410: 0x68880007  ldl         $t0, 0x7($a0)
    ctx->pc = 0x118410u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x118414: 0x6c880000  ldr         $t0, 0x0($a0)
    ctx->pc = 0x118414u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x118418: 0x6883000f  ldl         $v1, 0xF($a0)
    ctx->pc = 0x118418u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x11841c: 0x6c830008  ldr         $v1, 0x8($a0)
    ctx->pc = 0x11841cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x118420: 0x68850017  ldl         $a1, 0x17($a0)
    ctx->pc = 0x118420u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x118424: 0x6c850010  ldr         $a1, 0x10($a0)
    ctx->pc = 0x118424u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x118428: 0x6887001f  ldl         $a3, 0x1F($a0)
    ctx->pc = 0x118428u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x11842c: 0x6c870018  ldr         $a3, 0x18($a0)
    ctx->pc = 0x11842cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x118430: 0xb0c80007  sdl         $t0, 0x7($a2)
    ctx->pc = 0x118430u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118434: 0xb4c80000  sdr         $t0, 0x0($a2)
    ctx->pc = 0x118434u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118438: 0xb0c3000f  sdl         $v1, 0xF($a2)
    ctx->pc = 0x118438u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11843c: 0xb4c30008  sdr         $v1, 0x8($a2)
    ctx->pc = 0x11843cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118440: 0xb0c50017  sdl         $a1, 0x17($a2)
    ctx->pc = 0x118440u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118444: 0xb4c50010  sdr         $a1, 0x10($a2)
    ctx->pc = 0x118444u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118448: 0xb0c7001f  sdl         $a3, 0x1F($a2)
    ctx->pc = 0x118448u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11844c: 0xb4c70018  sdr         $a3, 0x18($a2)
    ctx->pc = 0x11844cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118450: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x118450u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x118454: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x118454u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x118458: 0x0  nop
    ctx->pc = 0x118458u;
    // NOP
    // 0x11845c: 0x1482ffec  bne         $a0, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x11845Cu;
    {
        const bool branch_taken_0x11845c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x11845c) {
            ctx->pc = 0x118410u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_118410;
        }
    }
    ctx->pc = 0x118464u;
    // 0x118464: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x118464u;
    {
        const bool branch_taken_0x118464 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x118464) {
            ctx->pc = 0x1184A0u;
            goto label_1184a0;
        }
    }
    ctx->pc = 0x11846Cu;
label_11846c:
    // 0x11846c: 0xdc880000  ld          $t0, 0x0($a0)
    ctx->pc = 0x11846cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x118470: 0xdc830008  ld          $v1, 0x8($a0)
    ctx->pc = 0x118470u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x118474: 0xdc850010  ld          $a1, 0x10($a0)
    ctx->pc = 0x118474u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x118478: 0xdc870018  ld          $a3, 0x18($a0)
    ctx->pc = 0x118478u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x11847c: 0xfcc80000  sd          $t0, 0x0($a2)
    ctx->pc = 0x11847cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 8));
    // 0x118480: 0xfcc30008  sd          $v1, 0x8($a2)
    ctx->pc = 0x118480u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 8), GPR_U64(ctx, 3));
    // 0x118484: 0xfcc50010  sd          $a1, 0x10($a2)
    ctx->pc = 0x118484u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 5));
    // 0x118488: 0xfcc70018  sd          $a3, 0x18($a2)
    ctx->pc = 0x118488u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 24), GPR_U64(ctx, 7));
    // 0x11848c: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x11848cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x118490: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x118490u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x118494: 0x0  nop
    ctx->pc = 0x118494u;
    // NOP
    // 0x118498: 0x1482fff4  bne         $a0, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x118498u;
    {
        const bool branch_taken_0x118498 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x118498) {
            ctx->pc = 0x11846Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11846c;
        }
    }
    ctx->pc = 0x1184A0u;
label_1184a0:
    // 0x1184a0: 0x88880003  lwl         $t0, 0x3($a0)
    ctx->pc = 0x1184a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x1184a4: 0x98880000  lwr         $t0, 0x0($a0)
    ctx->pc = 0x1184a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x1184a8: 0xa8c80003  swl         $t0, 0x3($a2)
    ctx->pc = 0x1184a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1184ac: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1184ACu;
    {
        const bool branch_taken_0x1184ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1184B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1184ACu;
            // 0x1184b0: 0xb8c80000  swr         $t0, 0x0($a2) (Delay Slot)
        { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1184ac) {
            ctx->pc = 0x118598u;
            goto label_118598;
        }
    }
    ctx->pc = 0x1184B4u;
label_1184b4:
    // 0x1184b4: 0x8a060017  lwl         $a2, 0x17($s0)
    ctx->pc = 0x1184b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 6) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 6, (int32_t)merged); }
    // 0x1184b8: 0x9a060014  lwr         $a2, 0x14($s0)
    ctx->pc = 0x1184b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 6) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 6) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 6, merged64); }
    // 0x1184bc: 0xaba60013  swl         $a2, 0x13($sp)
    ctx->pc = 0x1184bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 6); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1184c0: 0xbba60010  swr         $a2, 0x10($sp)
    ctx->pc = 0x1184c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 6); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x1184c4: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x1184c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1184c8: 0x6a03001f  ldl         $v1, 0x1F($s0)
    ctx->pc = 0x1184c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1184cc: 0x6e030018  ldr         $v1, 0x18($s0)
    ctx->pc = 0x1184ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1184d0: 0x6a040027  ldl         $a0, 0x27($s0)
    ctx->pc = 0x1184d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1184d4: 0x6e040020  ldr         $a0, 0x20($s0)
    ctx->pc = 0x1184d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1184d8: 0x6a05002f  ldl         $a1, 0x2F($s0)
    ctx->pc = 0x1184d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x1184dc: 0x6e050028  ldr         $a1, 0x28($s0)
    ctx->pc = 0x1184dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x1184e0: 0x6a060037  ldl         $a2, 0x37($s0)
    ctx->pc = 0x1184e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1184e4: 0x6e060030  ldr         $a2, 0x30($s0)
    ctx->pc = 0x1184e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1184e8: 0xb0430007  sdl         $v1, 0x7($v0)
    ctx->pc = 0x1184e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1184ec: 0xb4430000  sdr         $v1, 0x0($v0)
    ctx->pc = 0x1184ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1184f0: 0xb044000f  sdl         $a0, 0xF($v0)
    ctx->pc = 0x1184f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1184f4: 0xb4440008  sdr         $a0, 0x8($v0)
    ctx->pc = 0x1184f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1184f8: 0xb0450017  sdl         $a1, 0x17($v0)
    ctx->pc = 0x1184f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1184fc: 0xb4450010  sdr         $a1, 0x10($v0)
    ctx->pc = 0x1184fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118500: 0xb046001f  sdl         $a2, 0x1F($v0)
    ctx->pc = 0x118500u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118504: 0xb4460018  sdr         $a2, 0x18($v0)
    ctx->pc = 0x118504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118508: 0x6a03003f  ldl         $v1, 0x3F($s0)
    ctx->pc = 0x118508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x11850c: 0x6e030038  ldr         $v1, 0x38($s0)
    ctx->pc = 0x11850cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x118510: 0x6a040047  ldl         $a0, 0x47($s0)
    ctx->pc = 0x118510u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 71); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x118514: 0x6e040040  ldr         $a0, 0x40($s0)
    ctx->pc = 0x118514u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 64); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x118518: 0x6a05004f  ldl         $a1, 0x4F($s0)
    ctx->pc = 0x118518u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 79); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x11851c: 0x6e050048  ldr         $a1, 0x48($s0)
    ctx->pc = 0x11851cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 72); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x118520: 0x6a060057  ldl         $a2, 0x57($s0)
    ctx->pc = 0x118520u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 87); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x118524: 0x6e060050  ldr         $a2, 0x50($s0)
    ctx->pc = 0x118524u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 80); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x118528: 0xb0430027  sdl         $v1, 0x27($v0)
    ctx->pc = 0x118528u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11852c: 0xb4430020  sdr         $v1, 0x20($v0)
    ctx->pc = 0x11852cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118530: 0xb044002f  sdl         $a0, 0x2F($v0)
    ctx->pc = 0x118530u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118534: 0xb4440028  sdr         $a0, 0x28($v0)
    ctx->pc = 0x118534u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118538: 0xb0450037  sdl         $a1, 0x37($v0)
    ctx->pc = 0x118538u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11853c: 0xb4450030  sdr         $a1, 0x30($v0)
    ctx->pc = 0x11853cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118540: 0xb046003f  sdl         $a2, 0x3F($v0)
    ctx->pc = 0x118540u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118544: 0xb4460038  sdr         $a2, 0x38($v0)
    ctx->pc = 0x118544u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x118548: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x118548u;
    {
        const bool branch_taken_0x118548 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11854Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118548u;
            // 0x11854c: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118548) {
            ctx->pc = 0x11859Cu;
            goto label_11859c;
        }
    }
    ctx->pc = 0x118550u;
label_118550:
    // 0x118550: 0x8a070017  lwl         $a3, 0x17($s0)
    ctx->pc = 0x118550u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 7) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 7, (int32_t)merged); }
    // 0x118554: 0x9a070014  lwr         $a3, 0x14($s0)
    ctx->pc = 0x118554u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 7) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 7) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 7, merged64); }
    // 0x118558: 0xaba70013  swl         $a3, 0x13($sp)
    ctx->pc = 0x118558u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11855c: 0xbba70010  swr         $a3, 0x10($sp)
    ctx->pc = 0x11855cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 7); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x118560: 0x8a04001b  lwl         $a0, 0x1B($s0)
    ctx->pc = 0x118560u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x118564: 0x9a040018  lwr         $a0, 0x18($s0)
    ctx->pc = 0x118564u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x118568: 0xaba40017  swl         $a0, 0x17($sp)
    ctx->pc = 0x118568u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11856c: 0xbba40014  swr         $a0, 0x14($sp)
    ctx->pc = 0x11856cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x118570: 0x8fa60014  lw          $a2, 0x14($sp)
    ctx->pc = 0x118570u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x118574: 0x2cc20401  sltiu       $v0, $a2, 0x401
    ctx->pc = 0x118574u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
    // 0x118578: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x118578u;
    {
        const bool branch_taken_0x118578 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11857Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118578u;
            // 0x11857c: 0x8fa40010  lw          $a0, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118578) {
            ctx->pc = 0x118590u;
            goto label_118590;
        }
    }
    ctx->pc = 0x118580u;
    // 0x118580: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x118580u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x118584: 0x24060400  addiu       $a2, $zero, 0x400
    ctx->pc = 0x118584u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x118588: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x118588u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11858c: 0x8fa40010  lw          $a0, 0x10($sp)
    ctx->pc = 0x11858cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_118590:
    // 0x118590: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x118590u;
    SET_GPR_U32(ctx, 31, 0x118598u);
    ctx->pc = 0x118594u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118590u;
            // 0x118594: 0x2605001c  addiu       $a1, $s0, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118598u; }
        if (ctx->pc != 0x118598u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118598u; }
        if (ctx->pc != 0x118598u) { return; }
    }
    ctx->pc = 0x118598u;
label_118598:
    // 0x118598: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x118598u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_11859c:
    // 0x11859c: 0x4810019  bgez        $a0, . + 4 + (0x19 << 2)
    ctx->pc = 0x11859Cu;
    {
        const bool branch_taken_0x11859c = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1185A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11859Cu;
            // 0x1185a0: 0x3c070021  lui         $a3, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11859c) {
            ctx->pc = 0x118604u;
            goto label_118604;
        }
    }
    ctx->pc = 0x1185A4u;
    // 0x1185a4: 0x41023  negu        $v0, $a0
    ctx->pc = 0x1185a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x1185a8: 0x8ce39d58  lw          $v1, -0x62A8($a3)
    ctx->pc = 0x1185a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4294942040)));
    // 0x1185ac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1185acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1185b0: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1185b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1185b4: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1185B4u;
    {
        const bool branch_taken_0x1185b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1185B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1185B4u;
            // 0x1185b8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1185b4) {
            ctx->pc = 0x1185D0u;
            goto label_1185d0;
        }
    }
    ctx->pc = 0x1185BCu;
    // 0x1185bc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1185bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1185c0: 0xace29d58  sw          $v0, -0x62A8($a3)
    ctx->pc = 0x1185c0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294942040), GPR_U32(ctx, 2));
    // 0x1185c4: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1185C4u;
    {
        const bool branch_taken_0x1185c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1185C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1185C4u;
            // 0x1185c8: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1185c4) {
            ctx->pc = 0x118610u;
            goto label_118610;
        }
    }
    ctx->pc = 0x1185CCu;
    // 0x1185cc: 0x0  nop
    ctx->pc = 0x1185ccu;
    // NOP
label_1185d0:
    // 0x1185d0: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1185d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1185d4:
    // 0x1185d4: 0x28c20020  slti        $v0, $a2, 0x20
    ctx->pc = 0x1185d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1185d8: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1185D8u;
    {
        const bool branch_taken_0x1185d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1185DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1185D8u;
            // 0x1185dc: 0x24e29d58  addiu       $v0, $a3, -0x62A8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294942040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1185d8) {
            ctx->pc = 0x11860Cu;
            goto label_11860c;
        }
    }
    ctx->pc = 0x1185E0u;
    // 0x1185e0: 0x61880  sll         $v1, $a2, 2
    ctx->pc = 0x1185e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1185e4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1185e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1185e8: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1185e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1185ec: 0x1485fff9  bne         $a0, $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1185ECu;
    {
        const bool branch_taken_0x1185ec = (GPR_U64(ctx, 4) != GPR_U64(ctx, 5));
        ctx->pc = 0x1185F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1185ECu;
            // 0x1185f0: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1185ec) {
            ctx->pc = 0x1185D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1185d4;
        }
    }
    ctx->pc = 0x1185F4u;
    // 0x1185f4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1185f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1185f8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1185f8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1185fc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1185FCu;
    {
        const bool branch_taken_0x1185fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1185FCu;
            // 0x118600: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1185fc) {
            ctx->pc = 0x118610u;
            goto label_118610;
        }
    }
    ctx->pc = 0x118604u;
label_118604:
    // 0x118604: 0xc045194  jal         func_114650
    ctx->pc = 0x118604u;
    SET_GPR_U32(ctx, 31, 0x11860Cu);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11860Cu; }
        if (ctx->pc != 0x11860Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11860Cu; }
        if (ctx->pc != 0x11860Cu) { return; }
    }
    ctx->pc = 0x11860Cu;
label_11860c:
    // 0x11860c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11860cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_118610:
    // 0x118610: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x118610u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x118614: 0x3e00008  jr          $ra
    ctx->pc = 0x118614u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118614u;
            // 0x118618: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118214u: goto label_118214;
            case 0x11821Cu: goto label_11821c;
            case 0x118230u: goto label_118230;
            case 0x118238u: goto label_118238;
            case 0x11824Cu: goto label_11824c;
            case 0x118250u: goto label_118250;
            case 0x118288u: goto label_118288;
            case 0x118304u: goto label_118304;
            case 0x118330u: goto label_118330;
            case 0x118358u: goto label_118358;
            case 0x118380u: goto label_118380;
            case 0x1183A8u: goto label_1183a8;
            case 0x1183D8u: goto label_1183d8;
            case 0x118410u: goto label_118410;
            case 0x11846Cu: goto label_11846c;
            case 0x1184A0u: goto label_1184a0;
            case 0x1184B4u: goto label_1184b4;
            case 0x118550u: goto label_118550;
            case 0x118590u: goto label_118590;
            case 0x118598u: goto label_118598;
            case 0x11859Cu: goto label_11859c;
            case 0x1185D0u: goto label_1185d0;
            case 0x1185D4u: goto label_1185d4;
            case 0x118604u: goto label_118604;
            case 0x11860Cu: goto label_11860c;
            case 0x118610u: goto label_118610;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11861Cu;
    // 0x11861c: 0x0  nop
    ctx->pc = 0x11861cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
