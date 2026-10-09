#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001620C0
// Address: 0x1620c0 - 0x162510
void sub_001620C0_0x1620c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001620C0_0x1620c0");
#endif

    switch (ctx->pc) {
        case 0x162250u: goto label_162250;
        case 0x162264u: goto label_162264;
        case 0x162280u: goto label_162280;
        case 0x162290u: goto label_162290;
        case 0x1622a4u: goto label_1622a4;
        case 0x1622c4u: goto label_1622c4;
        case 0x1623a8u: goto label_1623a8;
        case 0x1623bcu: goto label_1623bc;
        case 0x1623d8u: goto label_1623d8;
        case 0x1623e8u: goto label_1623e8;
        case 0x1623fcu: goto label_1623fc;
        case 0x16241cu: goto label_16241c;
        case 0x162464u: goto label_162464;
        case 0x162490u: goto label_162490;
        case 0x1624c4u: goto label_1624c4;
        case 0x1624d8u: goto label_1624d8;
        case 0x1624f8u: goto label_1624f8;
        default: break;
    }

    ctx->pc = 0x1620c0u;

    // 0x1620c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1620c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1620c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1620c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1620c8: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x1620c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x1620cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1620ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1620d0: 0x805f5a2  j           func_17D688
    ctx->pc = 0x1620D0u;
    ctx->pc = 0x1620D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1620D0u;
            // 0x1620d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D688u;
    if (runtime->hasFunction(0x17D688u)) {
        auto targetFn = runtime->lookupFunction(0x17D688u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D688_0x17d688(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1620D8u;
    // 0x1620d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1620d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1620dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1620dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1620e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1620e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1620e4: 0x805882a  j           func_1620A8
    ctx->pc = 0x1620E4u;
    ctx->pc = 0x1620E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1620E4u;
            // 0x1620e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1620A8u;
    if (runtime->hasFunction(0x1620A8u)) {
        auto targetFn = runtime->lookupFunction(0x1620A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001620A8_0x1620a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1620ECu;
    // 0x1620ec: 0x0  nop
    ctx->pc = 0x1620ecu;
    // NOP
    // 0x1620f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1620f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1620f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1620f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1620f8: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x1620f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x1620fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1620fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162100: 0x805f5b2  j           func_17D6C8
    ctx->pc = 0x162100u;
    ctx->pc = 0x162104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162100u;
            // 0x162104: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D6C8u;
    if (runtime->hasFunction(0x17D6C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D6C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D6C8_0x17d6c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162108u;
    // 0x162108: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162108u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16210c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16210cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162110: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x162110u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x162114: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162118: 0x805f51c  j           func_17D470
    ctx->pc = 0x162118u;
    ctx->pc = 0x16211Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162118u;
            // 0x16211c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D470u;
    if (runtime->hasFunction(0x17D470u)) {
        auto targetFn = runtime->lookupFunction(0x17D470u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D470_0x17d470(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162120u;
    // 0x162120: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162124: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162128: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x162128u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x16212c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16212cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162130: 0x805f51e  j           func_17D478
    ctx->pc = 0x162130u;
    ctx->pc = 0x162134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162130u;
            // 0x162134: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D478u;
    if (runtime->hasFunction(0x17D478u)) {
        auto targetFn = runtime->lookupFunction(0x17D478u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D478_0x17d478(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162138u;
    // 0x162138: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16213c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16213cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162140: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x162140u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x162144: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162144u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162148: 0x805f520  j           func_17D480
    ctx->pc = 0x162148u;
    ctx->pc = 0x16214Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162148u;
            // 0x16214c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D480u;
    if (runtime->hasFunction(0x17D480u)) {
        auto targetFn = runtime->lookupFunction(0x17D480u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D480_0x17d480(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162150u;
    // 0x162150: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162154: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162154u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162158: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x162158u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x16215c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16215cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162160: 0x805f522  j           func_17D488
    ctx->pc = 0x162160u;
    ctx->pc = 0x162164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162160u;
            // 0x162164: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D488u;
    if (runtime->hasFunction(0x17D488u)) {
        auto targetFn = runtime->lookupFunction(0x17D488u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D488_0x17d488(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162168u;
    // 0x162168: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162168u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16216c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16216cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162170: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162170u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162174: 0x805f482  j           func_17D208
    ctx->pc = 0x162174u;
    ctx->pc = 0x162178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162174u;
            // 0x162178: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D208u;
    if (runtime->hasFunction(0x17D208u)) {
        auto targetFn = runtime->lookupFunction(0x17D208u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D208_0x17d208(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16217Cu;
    // 0x16217c: 0x0  nop
    ctx->pc = 0x16217cu;
    // NOP
    // 0x162180: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162180u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162184: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162188: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162188u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16218c: 0x805f486  j           func_17D218
    ctx->pc = 0x16218Cu;
    ctx->pc = 0x162190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16218Cu;
            // 0x162190: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D218u;
    if (runtime->hasFunction(0x17D218u)) {
        auto targetFn = runtime->lookupFunction(0x17D218u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D218_0x17d218(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162194u;
    // 0x162194: 0x0  nop
    ctx->pc = 0x162194u;
    // NOP
    // 0x162198: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16219c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x16219cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621a0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1621a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1621a4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1621a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621a8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1621a8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621ac: 0x8c4a000c  lw          $t2, 0xC($v0)
    ctx->pc = 0x1621acu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1621b0: 0x8c490008  lw          $t1, 0x8($v0)
    ctx->pc = 0x1621b0u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1621b4: 0xa1fc2  srl         $v1, $t2, 31
    ctx->pc = 0x1621b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
    // 0x1621b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1621b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1621bc: 0x1435021  addu        $t2, $t2, $v1
    ctx->pc = 0x1621bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x1621c0: 0xa5043  sra         $t2, $t2, 1
    ctx->pc = 0x1621c0u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 1));
    // 0x1621c4: 0x8058882  j           func_162208
    ctx->pc = 0x1621C4u;
    ctx->pc = 0x1621C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1621C4u;
            // 0x1621c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162208u;
    goto label_162208;
    ctx->pc = 0x1621CCu;
    // 0x1621cc: 0x0  nop
    ctx->pc = 0x1621ccu;
    // NOP
    // 0x1621d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1621d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1621d4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1621d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621d8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1621d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1621dc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1621dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621e0: 0x8c48000c  lw          $t0, 0xC($v0)
    ctx->pc = 0x1621e0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1621e4: 0x8c490008  lw          $t1, 0x8($v0)
    ctx->pc = 0x1621e4u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1621e8: 0x81fc2  srl         $v1, $t0, 31
    ctx->pc = 0x1621e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x1621ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1621ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1621f0: 0x1034021  addu        $t0, $t0, $v1
    ctx->pc = 0x1621f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1621f4: 0x84043  sra         $t0, $t0, 1
    ctx->pc = 0x1621f4u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
    // 0x1621f8: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1621f8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1621fc: 0x8058882  j           func_162208
    ctx->pc = 0x1621FCu;
    ctx->pc = 0x162200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1621FCu;
            // 0x162200: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162208u;
    goto label_162208;
    ctx->pc = 0x162204u;
    // 0x162204: 0x0  nop
    ctx->pc = 0x162204u;
    // NOP
label_162208:
    // 0x162208: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x162208u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x16220c: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x16220cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x162210: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x162210u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162214: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x162214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x162218: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x162218u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16221c: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x16221cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x162220: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x162220u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162224: 0xffb400b0  sd          $s4, 0xB0($sp)
    ctx->pc = 0x162224u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 20));
    // 0x162228: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x162228u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16222c: 0xffb500b8  sd          $s5, 0xB8($sp)
    ctx->pc = 0x16222cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 21));
    // 0x162230: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x162230u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162234: 0xffb600c0  sd          $s6, 0xC0($sp)
    ctx->pc = 0x162234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 22));
    // 0x162238: 0x120b02d  daddu       $s6, $t1, $zero
    ctx->pc = 0x162238u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16223c: 0xffb700c8  sd          $s7, 0xC8($sp)
    ctx->pc = 0x16223cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 200), GPR_U64(ctx, 23));
    // 0x162240: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x162240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x162244: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x162244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x162248: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x162248u;
    SET_GPR_U32(ctx, 31, 0x162250u);
    ctx->pc = 0x16224Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162248u;
            // 0x16224c: 0x140b82d  daddu       $s7, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162250u; }
        if (ctx->pc != 0x162250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162250u; }
        if (ctx->pc != 0x162250u) { return; }
    }
    ctx->pc = 0x162250u;
label_162250:
    // 0x162250: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x162250u;
    {
        const bool branch_taken_0x162250 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x162250) {
            ctx->pc = 0x162254u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162250u;
            // 0x162254: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162270u;
            goto label_162270;
        }
    }
    ctx->pc = 0x162258u;
    // 0x162258: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162258u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16225c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16225Cu;
    SET_GPR_U32(ctx, 31, 0x162264u);
    ctx->pc = 0x162260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16225Cu;
            // 0x162260: 0x2484ffc8  addiu       $a0, $a0, -0x38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162264u; }
        if (ctx->pc != 0x162264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162264u; }
        if (ctx->pc != 0x162264u) { return; }
    }
    ctx->pc = 0x162264u;
label_162264:
    // 0x162264: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x162264u;
    {
        const bool branch_taken_0x162264 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x162268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162264u;
            // 0x162268: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162264) {
            ctx->pc = 0x1622C8u;
            goto label_1622c8;
        }
    }
    ctx->pc = 0x16226Cu;
    // 0x16226c: 0x0  nop
    ctx->pc = 0x16226cu;
    // NOP
label_162270:
    // 0x162270: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x162270u;
    {
        const bool branch_taken_0x162270 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162270u;
            // 0x162274: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162270) {
            ctx->pc = 0x162288u;
            goto label_162288;
        }
    }
    ctx->pc = 0x162278u;
    // 0x162278: 0xc058dd4  jal         func_163750
    ctx->pc = 0x162278u;
    SET_GPR_U32(ctx, 31, 0x162280u);
    ctx->pc = 0x16227Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162278u;
            // 0x16227c: 0x24840000  addiu       $a0, $a0, 0x0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162280u; }
        if (ctx->pc != 0x162280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162280u; }
        if (ctx->pc != 0x162280u) { return; }
    }
    ctx->pc = 0x162280u;
label_162280:
    // 0x162280: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x162280u;
    {
        const bool branch_taken_0x162280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x162284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162280u;
            // 0x162284: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162280) {
            ctx->pc = 0x1622C8u;
            goto label_1622c8;
        }
    }
    ctx->pc = 0x162288u;
label_162288:
    // 0x162288: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x162288u;
    SET_GPR_U32(ctx, 31, 0x162290u);
    ctx->pc = 0x16228Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162288u;
            // 0x16228c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162290u; }
        if (ctx->pc != 0x162290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162290u; }
        if (ctx->pc != 0x162290u) { return; }
    }
    ctx->pc = 0x162290u;
label_162290:
    // 0x162290: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x162290u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162294: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x162294u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162298: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x162298u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16229c: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x16229Cu;
    SET_GPR_U32(ctx, 31, 0x1622A4u);
    ctx->pc = 0x1622A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16229Cu;
            // 0x1622a0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1622A4u; }
        if (ctx->pc != 0x1622A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1622A4u; }
        if (ctx->pc != 0x1622A4u) { return; }
    }
    ctx->pc = 0x1622A4u;
label_1622a4:
    // 0x1622a4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1622a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1622a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622ac: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1622acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622b0: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x1622b0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622b4: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x1622b4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622b8: 0x2c0482d  daddu       $t1, $s6, $zero
    ctx->pc = 0x1622b8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622bc: 0xc05ec04  jal         func_17B010
    ctx->pc = 0x1622BCu;
    SET_GPR_U32(ctx, 31, 0x1622C4u);
    ctx->pc = 0x1622C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1622BCu;
            // 0x1622c0: 0x2e0502d  daddu       $t2, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B010u;
    if (runtime->hasFunction(0x17B010u)) {
        auto targetFn = runtime->lookupFunction(0x17B010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1622C4u; }
        if (ctx->pc != 0x1622C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017B010_0x17b010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1622C4u; }
        if (ctx->pc != 0x1622C4u) { return; }
    }
    ctx->pc = 0x1622C4u;
label_1622c4:
    // 0x1622c4: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x1622c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1622c8:
    // 0x1622c8: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x1622c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x1622cc: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x1622ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1622d0: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x1622d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1622d4: 0xdfb400b0  ld          $s4, 0xB0($sp)
    ctx->pc = 0x1622d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1622d8: 0xdfb500b8  ld          $s5, 0xB8($sp)
    ctx->pc = 0x1622d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x1622dc: 0xdfb600c0  ld          $s6, 0xC0($sp)
    ctx->pc = 0x1622dcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1622e0: 0xdfb700c8  ld          $s7, 0xC8($sp)
    ctx->pc = 0x1622e0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x1622e4: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x1622e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1622e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1622E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1622ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1622E8u;
            // 0x1622ec: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162208u: goto label_162208;
            case 0x162250u: goto label_162250;
            case 0x162264u: goto label_162264;
            case 0x162270u: goto label_162270;
            case 0x162280u: goto label_162280;
            case 0x162288u: goto label_162288;
            case 0x162290u: goto label_162290;
            case 0x1622A4u: goto label_1622a4;
            case 0x1622C4u: goto label_1622c4;
            case 0x1622C8u: goto label_1622c8;
            case 0x162360u: goto label_162360;
            case 0x1623A8u: goto label_1623a8;
            case 0x1623BCu: goto label_1623bc;
            case 0x1623C8u: goto label_1623c8;
            case 0x1623D8u: goto label_1623d8;
            case 0x1623E0u: goto label_1623e0;
            case 0x1623E8u: goto label_1623e8;
            case 0x1623FCu: goto label_1623fc;
            case 0x16241Cu: goto label_16241c;
            case 0x162420u: goto label_162420;
            case 0x162464u: goto label_162464;
            case 0x162488u: goto label_162488;
            case 0x162490u: goto label_162490;
            case 0x1624C4u: goto label_1624c4;
            case 0x1624D8u: goto label_1624d8;
            case 0x1624F0u: goto label_1624f0;
            case 0x1624F8u: goto label_1624f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1622F0u;
    // 0x1622f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1622f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1622f4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1622f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1622f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1622f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1622fc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1622fcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162300: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x162300u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162304: 0x8c4a000c  lw          $t2, 0xC($v0)
    ctx->pc = 0x162304u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x162308: 0x8c490008  lw          $t1, 0x8($v0)
    ctx->pc = 0x162308u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x16230c: 0xa1fc2  srl         $v1, $t2, 31
    ctx->pc = 0x16230cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
    // 0x162310: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162310u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162314: 0x1435021  addu        $t2, $t2, $v1
    ctx->pc = 0x162314u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x162318: 0xa5043  sra         $t2, $t2, 1
    ctx->pc = 0x162318u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 1));
    // 0x16231c: 0x80588d8  j           func_162360
    ctx->pc = 0x16231Cu;
    ctx->pc = 0x162320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16231Cu;
            // 0x162320: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162360u;
    goto label_162360;
    ctx->pc = 0x162324u;
    // 0x162324: 0x0  nop
    ctx->pc = 0x162324u;
    // NOP
    // 0x162328: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16232c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x16232cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162330: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162334: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x162334u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162338: 0x8c48000c  lw          $t0, 0xC($v0)
    ctx->pc = 0x162338u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x16233c: 0x8c490008  lw          $t1, 0x8($v0)
    ctx->pc = 0x16233cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x162340: 0x81fc2  srl         $v1, $t0, 31
    ctx->pc = 0x162340u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 31));
    // 0x162344: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162344u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162348: 0x1034021  addu        $t0, $t0, $v1
    ctx->pc = 0x162348u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x16234c: 0x84043  sra         $t0, $t0, 1
    ctx->pc = 0x16234cu;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
    // 0x162350: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x162350u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162354: 0x80588d8  j           func_162360
    ctx->pc = 0x162354u;
    ctx->pc = 0x162358u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162354u;
            // 0x162358: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162360u;
    goto label_162360;
    ctx->pc = 0x16235Cu;
    // 0x16235c: 0x0  nop
    ctx->pc = 0x16235cu;
    // NOP
label_162360:
    // 0x162360: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x162360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x162364: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x162364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x162368: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x162368u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16236c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x16236cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x162370: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x162370u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162374: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x162374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x162378: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x162378u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16237c: 0xffb400b0  sd          $s4, 0xB0($sp)
    ctx->pc = 0x16237cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 20));
    // 0x162380: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x162380u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162384: 0xffb500b8  sd          $s5, 0xB8($sp)
    ctx->pc = 0x162384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 21));
    // 0x162388: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x162388u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16238c: 0xffb600c0  sd          $s6, 0xC0($sp)
    ctx->pc = 0x16238cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 22));
    // 0x162390: 0x120b02d  daddu       $s6, $t1, $zero
    ctx->pc = 0x162390u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162394: 0xffb700c8  sd          $s7, 0xC8($sp)
    ctx->pc = 0x162394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 200), GPR_U64(ctx, 23));
    // 0x162398: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x162398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x16239c: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x16239cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x1623a0: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1623A0u;
    SET_GPR_U32(ctx, 31, 0x1623A8u);
    ctx->pc = 0x1623A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623A0u;
            // 0x1623a4: 0x140b82d  daddu       $s7, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623A8u; }
        if (ctx->pc != 0x1623A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623A8u; }
        if (ctx->pc != 0x1623A8u) { return; }
    }
    ctx->pc = 0x1623A8u;
label_1623a8:
    // 0x1623a8: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1623A8u;
    {
        const bool branch_taken_0x1623a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1623a8) {
            ctx->pc = 0x1623ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1623A8u;
            // 0x1623ac: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1623C8u;
            goto label_1623c8;
        }
    }
    ctx->pc = 0x1623B0u;
    // 0x1623b0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1623b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1623b4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1623B4u;
    SET_GPR_U32(ctx, 31, 0x1623BCu);
    ctx->pc = 0x1623B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623B4u;
            // 0x1623b8: 0x24840038  addiu       $a0, $a0, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623BCu; }
        if (ctx->pc != 0x1623BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623BCu; }
        if (ctx->pc != 0x1623BCu) { return; }
    }
    ctx->pc = 0x1623BCu;
label_1623bc:
    // 0x1623bc: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1623BCu;
    {
        const bool branch_taken_0x1623bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1623C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1623BCu;
            // 0x1623c0: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1623bc) {
            ctx->pc = 0x162420u;
            goto label_162420;
        }
    }
    ctx->pc = 0x1623C4u;
    // 0x1623c4: 0x0  nop
    ctx->pc = 0x1623c4u;
    // NOP
label_1623c8:
    // 0x1623c8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1623C8u;
    {
        const bool branch_taken_0x1623c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1623CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1623C8u;
            // 0x1623cc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1623c8) {
            ctx->pc = 0x1623E0u;
            goto label_1623e0;
        }
    }
    ctx->pc = 0x1623D0u;
    // 0x1623d0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1623D0u;
    SET_GPR_U32(ctx, 31, 0x1623D8u);
    ctx->pc = 0x1623D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623D0u;
            // 0x1623d4: 0x24840070  addiu       $a0, $a0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623D8u; }
        if (ctx->pc != 0x1623D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623D8u; }
        if (ctx->pc != 0x1623D8u) { return; }
    }
    ctx->pc = 0x1623D8u;
label_1623d8:
    // 0x1623d8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1623D8u;
    {
        const bool branch_taken_0x1623d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1623DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1623D8u;
            // 0x1623dc: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1623d8) {
            ctx->pc = 0x162420u;
            goto label_162420;
        }
    }
    ctx->pc = 0x1623E0u;
label_1623e0:
    // 0x1623e0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1623E0u;
    SET_GPR_U32(ctx, 31, 0x1623E8u);
    ctx->pc = 0x1623E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623E0u;
            // 0x1623e4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623E8u; }
        if (ctx->pc != 0x1623E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623E8u; }
        if (ctx->pc != 0x1623E8u) { return; }
    }
    ctx->pc = 0x1623E8u;
label_1623e8:
    // 0x1623e8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1623e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1623ec: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1623ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1623f0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1623f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1623f4: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x1623F4u;
    SET_GPR_U32(ctx, 31, 0x1623FCu);
    ctx->pc = 0x1623F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1623F4u;
            // 0x1623f8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623FCu; }
        if (ctx->pc != 0x1623FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1623FCu; }
        if (ctx->pc != 0x1623FCu) { return; }
    }
    ctx->pc = 0x1623FCu;
label_1623fc:
    // 0x1623fc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1623fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162400: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162400u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162404: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x162404u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162408: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x162408u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16240c: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x16240cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162410: 0x2c0482d  daddu       $t1, $s6, $zero
    ctx->pc = 0x162410u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162414: 0xc05eeba  jal         func_17BAE8
    ctx->pc = 0x162414u;
    SET_GPR_U32(ctx, 31, 0x16241Cu);
    ctx->pc = 0x162418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162414u;
            // 0x162418: 0x2e0502d  daddu       $t2, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BAE8u;
    if (runtime->hasFunction(0x17BAE8u)) {
        auto targetFn = runtime->lookupFunction(0x17BAE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16241Cu; }
        if (ctx->pc != 0x16241Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017BAE8_0x17bae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16241Cu; }
        if (ctx->pc != 0x16241Cu) { return; }
    }
    ctx->pc = 0x16241Cu;
label_16241c:
    // 0x16241c: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x16241cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_162420:
    // 0x162420: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x162420u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x162424: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x162424u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x162428: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x162428u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x16242c: 0xdfb400b0  ld          $s4, 0xB0($sp)
    ctx->pc = 0x16242cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x162430: 0xdfb500b8  ld          $s5, 0xB8($sp)
    ctx->pc = 0x162430u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x162434: 0xdfb600c0  ld          $s6, 0xC0($sp)
    ctx->pc = 0x162434u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x162438: 0xdfb700c8  ld          $s7, 0xC8($sp)
    ctx->pc = 0x162438u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 200)));
    // 0x16243c: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x16243cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x162440: 0x3e00008  jr          $ra
    ctx->pc = 0x162440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162440u;
            // 0x162444: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162208u: goto label_162208;
            case 0x162250u: goto label_162250;
            case 0x162264u: goto label_162264;
            case 0x162270u: goto label_162270;
            case 0x162280u: goto label_162280;
            case 0x162288u: goto label_162288;
            case 0x162290u: goto label_162290;
            case 0x1622A4u: goto label_1622a4;
            case 0x1622C4u: goto label_1622c4;
            case 0x1622C8u: goto label_1622c8;
            case 0x162360u: goto label_162360;
            case 0x1623A8u: goto label_1623a8;
            case 0x1623BCu: goto label_1623bc;
            case 0x1623C8u: goto label_1623c8;
            case 0x1623D8u: goto label_1623d8;
            case 0x1623E0u: goto label_1623e0;
            case 0x1623E8u: goto label_1623e8;
            case 0x1623FCu: goto label_1623fc;
            case 0x16241Cu: goto label_16241c;
            case 0x162420u: goto label_162420;
            case 0x162464u: goto label_162464;
            case 0x162488u: goto label_162488;
            case 0x162490u: goto label_162490;
            case 0x1624C4u: goto label_1624c4;
            case 0x1624D8u: goto label_1624d8;
            case 0x1624F0u: goto label_1624f0;
            case 0x1624F8u: goto label_1624f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162448u;
    // 0x162448: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162448u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16244c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16244cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162450: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x162450u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162454: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x162454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162458: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16245c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16245Cu;
    SET_GPR_U32(ctx, 31, 0x162464u);
    ctx->pc = 0x162460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16245Cu;
            // 0x162460: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162464u; }
        if (ctx->pc != 0x162464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162464u; }
        if (ctx->pc != 0x162464u) { return; }
    }
    ctx->pc = 0x162464u;
label_162464:
    // 0x162464: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x162464u;
    {
        const bool branch_taken_0x162464 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162464u;
            // 0x162468: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162464) {
            ctx->pc = 0x162488u;
            goto label_162488;
        }
    }
    ctx->pc = 0x16246Cu;
    // 0x16246c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16246cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162470: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162470u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162474: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162474u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162478: 0x248400a8  addiu       $a0, $a0, 0xA8
    ctx->pc = 0x162478u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 168));
    // 0x16247c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16247cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162480: 0x8058dd4  j           func_163750
    ctx->pc = 0x162480u;
    ctx->pc = 0x162484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162480u;
            // 0x162484: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162488u;
label_162488:
    // 0x162488: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x162488u;
    SET_GPR_U32(ctx, 31, 0x162490u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162490u; }
        if (ctx->pc != 0x162490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162490u; }
        if (ctx->pc != 0x162490u) { return; }
    }
    ctx->pc = 0x162490u;
label_162490:
    // 0x162490: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x162490u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162494: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162494u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162498: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x162498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16249c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16249cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1624a0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1624a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1624a4: 0x805f57c  j           func_17D5F0
    ctx->pc = 0x1624A4u;
    ctx->pc = 0x1624A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1624A4u;
            // 0x1624a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D5F0u;
    if (runtime->hasFunction(0x17D5F0u)) {
        auto targetFn = runtime->lookupFunction(0x17D5F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D5F0_0x17d5f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1624ACu;
    // 0x1624ac: 0x0  nop
    ctx->pc = 0x1624acu;
    // NOP
    // 0x1624b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1624b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1624b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1624b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1624b8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1624b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1624bc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1624BCu;
    SET_GPR_U32(ctx, 31, 0x1624C4u);
    ctx->pc = 0x1624C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1624BCu;
            // 0x1624c0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624C4u; }
        if (ctx->pc != 0x1624C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624C4u; }
        if (ctx->pc != 0x1624C4u) { return; }
    }
    ctx->pc = 0x1624C4u;
label_1624c4:
    // 0x1624c4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1624C4u;
    {
        const bool branch_taken_0x1624c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1624C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1624C4u;
            // 0x1624c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1624c4) {
            ctx->pc = 0x1624F0u;
            goto label_1624f0;
        }
    }
    ctx->pc = 0x1624CCu;
    // 0x1624cc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1624ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1624d0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1624D0u;
    SET_GPR_U32(ctx, 31, 0x1624D8u);
    ctx->pc = 0x1624D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1624D0u;
            // 0x1624d4: 0x248400d8  addiu       $a0, $a0, 0xD8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624D8u; }
        if (ctx->pc != 0x1624D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624D8u; }
        if (ctx->pc != 0x1624D8u) { return; }
    }
    ctx->pc = 0x1624D8u;
label_1624d8:
    // 0x1624d8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1624d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1624dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1624dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1624e0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1624e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1624e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1624E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1624E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1624E4u;
            // 0x1624e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162208u: goto label_162208;
            case 0x162250u: goto label_162250;
            case 0x162264u: goto label_162264;
            case 0x162270u: goto label_162270;
            case 0x162280u: goto label_162280;
            case 0x162288u: goto label_162288;
            case 0x162290u: goto label_162290;
            case 0x1622A4u: goto label_1622a4;
            case 0x1622C4u: goto label_1622c4;
            case 0x1622C8u: goto label_1622c8;
            case 0x162360u: goto label_162360;
            case 0x1623A8u: goto label_1623a8;
            case 0x1623BCu: goto label_1623bc;
            case 0x1623C8u: goto label_1623c8;
            case 0x1623D8u: goto label_1623d8;
            case 0x1623E0u: goto label_1623e0;
            case 0x1623E8u: goto label_1623e8;
            case 0x1623FCu: goto label_1623fc;
            case 0x16241Cu: goto label_16241c;
            case 0x162420u: goto label_162420;
            case 0x162464u: goto label_162464;
            case 0x162488u: goto label_162488;
            case 0x162490u: goto label_162490;
            case 0x1624C4u: goto label_1624c4;
            case 0x1624D8u: goto label_1624d8;
            case 0x1624F0u: goto label_1624f0;
            case 0x1624F8u: goto label_1624f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1624ECu;
    // 0x1624ec: 0x0  nop
    ctx->pc = 0x1624ecu;
    // NOP
label_1624f0:
    // 0x1624f0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1624F0u;
    SET_GPR_U32(ctx, 31, 0x1624F8u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624F8u; }
        if (ctx->pc != 0x1624F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624F8u; }
        if (ctx->pc != 0x1624F8u) { return; }
    }
    ctx->pc = 0x1624F8u;
label_1624f8:
    // 0x1624f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1624f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1624fc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1624fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162500: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162500u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162504: 0x805f588  j           func_17D620
    ctx->pc = 0x162504u;
    ctx->pc = 0x162508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162504u;
            // 0x162508: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D620u;
    if (runtime->hasFunction(0x17D620u)) {
        auto targetFn = runtime->lookupFunction(0x17D620u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D620_0x17d620(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16250Cu;
    // 0x16250c: 0x0  nop
    ctx->pc = 0x16250cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
